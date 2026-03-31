import numpy as np

class Dikin:
    def __init__(self, matrix, b, c):
        self.A = np.array(matrix, np.float64)
        self.b = np.array(b, np.float64)
        self.c = c
    def initialize(self):
        delta = 2/3
        # 1. Chute inicial estritamente positivo (vamos usar um vetor de 1s)
        n = self.A.shape[1]
        x_chute = np.ones(n, dtype=np.float64)
        
        # 2. Calcula o resíduo 'r' (o quanto o chute inicial errou o alvo 'b')
        r = self.b - (self.A @ x_chute)
        
        # Se por muita sorte o chute já for viável (resíduo quase zero), acabamos!
        if np.linalg.norm(r) < 1e-08:
            return x_chute
            
        # 3. Prepara o Problema Auxiliar (Fase I)
        # Colocamos o vetor 'r' como uma nova coluna na matriz A
        A_aux = np.column_stack((self.A, r))
        
        # O novo custo é focado APENAS em zerar a variável artificial (a última).
        # Custo = [0, 0, ..., 0, 1]
        c_aux = np.zeros(n + 1, dtype=np.float64)
        c_aux[-1] = 1.0
        
        # O nosso ponto inicial garantido: [x_chute, 1]
        # Como o chute é de 1s e a variável artificial é 1, ele é estritamente positivo (> 0)
        sol_aux = np.ones(n + 1, dtype=np.float64)
        
        # Parâmetros para a Fase I
        eps = 1e-08
        
        # 4. Rodamos o Dikin para o problema auxiliar
        # Condição de parada: a variável artificial (sol_aux[-1]) chegou a zero
        k = 0
        while sol_aux[-1] > eps:
            D = np.diag(sol_aux)
            Abar = A_aux @ D
            cbar = D @ c_aux
            
            # Matriz de projeção (criando o caminho pelo Espaço Nulo)
            AbarT = np.transpose(Abar)
            inv_part = np.linalg.inv(Abar @ AbarT)
            P = np.identity(Abar.shape[1]) - AbarT @ inv_part @ Abar
            
            # Direção
            Pcbar = P @ cbar
            dbar = -Pcbar
            direction = D @ dbar
                
            mask = direction < 0
            
            if np.any(mask):
                ratios = -sol_aux[mask] / direction[mask]
                gamma = np.min(ratios)
            else:
                gamma = 1.0
                

            sol_aux += (delta * gamma) * direction
            k += 1

        return sol_aux[:-1]

    def dikin(self):
        sol = self.initialize()
        k = 0
        eps = 1e-08
        stop = False
        while not np.any(sol < eps):
            D = np.diag(sol)

            Abar = self.A @ D
            cbar = D @ self.c

            # Calculamos a matrix de projeção
            Abartranspose = np.transpose(Abar)
            P = np.identity(Abar.shape[1]) - Abartranspose @ np.linalg.inv(Abar @ Abartranspose) @ Abar

            # Agora a direção
            Pcbar = P @ cbar
            dbar = -Pcbar / np.linalg.norm(Pcbar)

            # Reescalamos
            direction = D @ dbar

            sol += direction
            k += 1
        
        return sol
    
class AffineScalling:
    def __init__(self, matrix, b, c):
        self.A = np.array(matrix, np.float64)
        self.b = np.array(b, np.float64)
        self.c = np.array(c, np.float64)

    def initialize(self):
        # 1. Chute inicial estritamente positivo (vamos usar um vetor de 1s)
        n = self.A.shape[1]
        x_chute = np.ones(n, dtype=np.float64)
        
        # 2. Calcula o resíduo 'r' (o quanto o chute inicial errou o alvo 'b')
        r = self.b - (self.A @ x_chute)
        
        # Se por muita sorte o chute já for viável (resíduo quase zero), acabamos!
        if np.linalg.norm(r) < 1e-08:
            return x_chute
            
        # 3. Prepara o Problema Auxiliar (Fase I)
        # Colocamos o vetor 'r' como uma nova coluna na matriz A
        A_aux = np.column_stack((self.A, r))
        
        # O novo custo é focado APENAS em zerar a variável artificial (a última).
        # Custo = [0, 0, ..., 0, 1]
        c_aux = np.zeros(n + 1, dtype=np.float64)
        c_aux[-1] = 1.0
        
        # O nosso ponto inicial garantido: [x_chute, 1]
        # Como o chute é de 1s e a variável artificial é 1, ele é estritamente positivo (> 0)
        sol_aux = np.ones(n + 1, dtype=np.float64)
        
        # Parâmetros para a Fase I
        eps = 1e-08
        delta = 2 / 3
        
        # 4. Rodamos o Dikin para o problema auxiliar
        # Condição de parada: a variável artificial (sol_aux[-1]) chegou a zero
        while sol_aux[-1] > eps:
            D = np.diag(sol_aux)
            Abar = A_aux @ D
            cbar = D @ c_aux
            
            # Matriz de projeção (criando o caminho pelo Espaço Nulo)
            AbarT = np.transpose(Abar)
            inv_part = np.linalg.inv(Abar @ AbarT)
            P = np.identity(Abar.shape[1]) - AbarT @ inv_part @ Abar
            
            # Direção
            Pcbar = P @ cbar
            dbar = -Pcbar
            direction = D @ dbar
            
            # Teste da razão para não bater nas paredes (não deixar nenhuma variável <= 0)
            mask = direction < 0
            if np.any(mask):
                ratios = -sol_aux[mask] / direction[mask]
                gamma = np.min(ratios)
            else:
                gamma = 1.0 # Se não há direções negativas, andamos o passo todo
                
            sol_aux += (delta * gamma) * direction
            
        # 5. Fim da Fase I! 
        # A variável artificial zerou. As primeiras 'n' variáveis de sol_aux
        # agora formam o nosso x0 interior e viável para o problema real.
        return sol_aux[:-1]

    def affine_scalling(self):
        sol = self.initialize()
        eps = 1e-08
        delta = 2 / 3
        k = 0
        stop = False
        while not np.any(sol < eps):
            D = np.diag(sol)

            Abar = self.A @ D
            cbar = D @ self.c

            # Calculamos a matrix de projeção
            Abartranspose = np.transpose(Abar)
            P = np.identity(Abar.shape[1]) - Abartranspose @ np.linalg.inv(Abar @ Abartranspose) @ Abar

            # Agora a direção
            Pcbar = P @ cbar
            dbar = -Pcbar

            # Reescalamos
            direction = D @ dbar

            # Teste da razão
            mask = direction < 0

            if np.any(mask):
                ratios = -sol[mask] / direction[mask]
                gamma = np.min(ratios)
            else:
                gamma = 1.0

            sol += (delta * gamma) * direction
            k += 1
        
        return sol


if __name__ == "__main__":
    
    A = [
        [3, 4, 1, 0, 0, 0],
        [2, 3, 0, 1, 0, 0],
        [1, 2, 0, 0, 1, 0],
        [0, -1, 0, 0, 0, 1]
    ]
    b = [100, 70, 30, -3]
    
    c = [-15, -25, 0, 0, 0, 0]

    print("Testando Affine Scaling...")
    solver_affine = AffineScalling(A, b, c)
    sol_affine = solver_affine.affine_scalling()
    print("Solução Affine Scaling (x1, x2, f1, f2, f3, f4):")
    print(np.round(sol_affine, 2))
    print(f"Lucro Máximo Encontrado: {-np.dot(c, sol_affine):.2f}\n")

    print("Testando Dikin...")
    solver_dikin = Dikin(A, b, c)
    sol_dikin = solver_dikin.dikin()
    print("Solução Dikin (x1, x2, f1, f2, f3, f4):")
    print(np.round(sol_dikin, 2))
    print(f"Lucro Máximo Encontrado: {-np.dot(c, sol_dikin):.2f}")