from numpy.linalg import solve

A = [
    [0.001, 0],
    [1, 1000]
]

b = [2, 1]

print(solve(A, b))