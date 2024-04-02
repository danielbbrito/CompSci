import math
import numpy as np


def jacobi(A, n, b, x0, e):
    k = 0
    for
    for i in range(n):
        r = 1 / A[i][i]
        for j in range(n):
            if i != j:
                A[i][j] *= r
        
        b[i] *= r