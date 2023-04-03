from matplotlib import pyplot as plt
import numpy as np
am_of_ells = [100 ,228 ,400 ,1337 ,1600 ,3200 ,5000 ,7000 ,10000 ,15000 ,20000 ,25000 ,35000 ,45000 ,60000 ,75000 ,95000 ,115000 ,]
time = [3 ,6 ,9 ,28 ,31 ,64 ,138 ,168 ,242 ,404 ,555 ,752 ,1055 ,1394 ,1799 ,2312 ,2897 ,3554 ,]
plt.grid()
plt.plot(am_of_ells, time, '.')
plt.savefig('josephus_boof')
plt.show()