# -*- coding: utf-8 -*-
from math import sqrt
import matplotlib.pyplot as plt

def linear_regression(x: list, y: list) -> tuple:
    '''
    

    Parameters
    ----------
    x : list
        Conjunto de valores para x.
    y : list
        Cojunto de valores para y.

    Returns
    -------
    tuple
        valores de w0 e w1, os coeficientes da função linear que melhor representa o dataset, 
        sendo w1 o coeficiente angular e w0 o intercepto.

    '''
    
    N = len(x)
    
    soma_xy = 0
    soma_x = 0
    soma_y = 0
    soma_x2 = 0
    
    for i in range(N):
        soma_xy += x[i] * y[i]
        soma_x += x[i]
        soma_y += y[i]
        soma_x2 += x[i] ** 2
        
    w1 = (N * soma_xy - soma_x * soma_y) / (N * soma_x2 - soma_x ** 2)
    w0 = (soma_y - w1 * soma_x) / N
    
    return (w1, w0)


def squared_loss(y: list, y_predict: list) -> float:
    N = len(y)
    
    loss = 0
    
    for i in range(N):
        loss += (y[i] - y_predict[i]) ** 2
        
    return loss


def mean_squared_error(y: list, y_predict: list) -> float:
    N = len(y)

    return squared_loss(y, y_predict) / N


def root_mean_squared_error(y: list, y_predict: list) -> float:
    return sqrt(mean_squared_error(y, y_predict))


def main():
    
    x = [3, 7, 11, 15, 18, 27, 29, 30, 31, 31, 32, 33, 33, 34, 36, 36,
         36, 37, 38, 39, 39, 39, 40, 41, 42, 42, 43, 44, 45, 46, 47, 50]

    y = [5, 11, 21, 16, 16, 28, 27, 25, 35, 30, 40, 32, 34, 32, 
         34, 37, 38, 34, 36, 38, 37, 36, 45, 39, 41, 40, 44, 37, 44, 46, 46, 49]
    
    w1, w0 = linear_regression(x, y)
    
    y_predict = [w1 * x[i] + w0 for i in range(len(x))]
   
    
    SE = squared_loss(y, y_predict)
    MSE = mean_squared_error(y, y_predict)
    RMSE = root_mean_squared_error(y, y_predict)
    
    print("Função prevista:\n")
    print(f"Hw(x) = {w1}x + {w0}")
    print(f"w1={w1}\nw0={w0}\n")
    
    print("Prevendo o valor quando há uma redução de 30% de sólidos totais:")
    print("x=30")
    print("y_real=31")
    print(f"y_previsto={w1 * 30 + w0}\n")

    print("Medidas de precisao do modelo")    
    print("Erro quadrado:")
    print(f"SE={SE}\n")
    
    print("Erro quadrado médio:")
    print(f"MSE={MSE}\nß")
    
    print("Raíz do erro quadrado médio: ")
    print(f"RMSE={RMSE}")
    
    plt.scatter(x, y)
    plt.plot(x, y_predict, color="#FF0000")
    
    for i in range(len(x)):
        plt.plot([x[i], x[i]], [y[i], y_predict[i]], linestyle="--")
        
    plt.xlabel("Reducao de solidos totais %")
    plt.ylabel("Reducao na demanda de oxigenio quimico %")
    plt.show()
    
    
    
    
if __name__ == "__main__":
    main()