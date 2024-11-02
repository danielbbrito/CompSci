import numpy as np
import matplotlib.pyplot as plt

x = ["C++", "C+", "Python", "Java", "Go"]

y = [20, 50, 140, 1, 45]

plt.bar(x, y, color="red", align="edge", width=1, edgecolor="blue", lw=6)
plt.show()