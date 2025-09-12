import pandas as pd
import matplotlib.pyplot as plt

beer_cosumption = pd.read_csv("beer_consuption.csv", parse_dates=["Data"], date_format="%d/%m/%Y")

#plt.subplot(1, 1, 1)
plt.scatter(beer_cosumption["Temperatura Media (C)"], beer_cosumption["Consumo de cerveja (litros)"])
plt.xlabel("Temperatura média")
plt.ylabel("Consumo")
plt.show()
print(matplotlib.get_backend())