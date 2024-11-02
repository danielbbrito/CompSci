import numpy as np
import matplotlib.pyplot as plt


langs = ["C++", "C+", "Python", "Java", "Go"]

votes = [20, 50, 140, 1, 45]

explodes = [0, 0, 0, 0, 0.2]

plt.pie(votes, labels=langs, explode=explodes, autopct="%.2f", pctdistance=1.5)
plt.show()