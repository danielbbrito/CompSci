import pandas as pd
runtime = [[1],
           [2],
           [3]]

algos = [1,2,3]
sizes=[1]
df_runtime = pd.DataFrame(runtime, index=algos, columns=sizes)
df_runtime.to_excel("random.xlsx")