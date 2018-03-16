import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl






beamCur = [ 5, 5, 5, 10, 2.5, 2.5, 2.5, 2.5, 7.1, 7.1, 7.1 , 1, 10]
irradTime = [10, 30, 60, 10, 10, 120, 30, 60, 10, 60, 30, 60, 30]
storage = [32.7, 31.9, 29.6, 29.4, 32.7, 31.4, 31.3, 32.7, 33.5, 28.2, 29.7
           , 34.33, 27.6]
storageErr = [0.5, 0.3, 0.3, 0.3, 0.5, 0.4, 0.4, 0.4, 0.6, 0.2, 0.2, 0.7,
              0.2]

fig, ax = plt.subplots()
plt.scatter (irradTime, beamCur, c=storage, s= 50, cmap= mpl.cm.Reds)
plt.colorbar()
plt.title("Beam Current vs Irradiation Time")
plt.xlabel("Irradiation Time (s)")
plt.ylabel("Beam Current ($\mu$A)")
plt.show()
