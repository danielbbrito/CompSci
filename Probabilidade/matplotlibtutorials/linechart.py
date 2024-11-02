import numpy  as np
import matplotlib.pyplot as plt


years = [2010 + x for x in range(15)]
weights = [57, 60, 62, 67, 70, 75, 81, 87, 90, 91, 90, 97, 100, 105, 107]

# Creates a line chart using two sets of coordinates X, Y. lw is line width
plt.plot(years, weights, lw=3, linestyle="--")
plt.show()