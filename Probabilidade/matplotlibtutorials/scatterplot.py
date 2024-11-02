import numpy as np
import matplotlib.pyplot as plt

x_data = np.random.random(50) * 100
y_data = np.random.random(50) * 100

# create a scatterplot with matplotlib
plt.scatter(x_data, y_data, c="red", s=150, marker=".", alpha=0.5)
plt.show()