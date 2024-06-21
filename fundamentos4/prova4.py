import numpy as np
def metodo_potencia(A, num_iterations= 1000, tol= 1e-6):
    # Vetor inicial
    x = np.random.rand(A.shape[1])
    
    for _ in range(num_iterations):
        # Multiplicação pela matriz
        x1 = np.dot(A, x)
        
        # Normalização
        x1_norm = np.linalg.norm(x1)
        x = x1 / x1_norm
        
        if np.linalg.norm(np.dot(A, x) - x1_norm * x) < tol:
            break

    autovalor = x1_norm
    autovetor = x
    return autovalor, autovetor

# Exemplo de matriz
A = np.array([
    [0, 1, 0, 1, 0],
    [1, 0, 1, 0, 0],
    [0, 1, 0, 1, 1],
    [1, 0, 1, 0, 0],
    [0, 0, 1, 0, 0]
])

autovalor, autovetor = metodo_potencia(A)
print("Autovalor principal:", autovalor)
print("Autovetor principal:", autovetor)