from matplotlib import pyplot as plt
import numpy as np
am_of_ells = [100 ,228 ,400 ,1337 ,1600 ,3200 ,5000 ,7000 ,10000 ,15000 ,20000 ,25000 ,35000 ,]
time = [0 ,1 ,7 ,35 ,18 ,64 ,77 ,97 ,139 ,237 ,257 ,283 ,520 ,]
plt.grid()
plt.plot(am_of_ells, time, '.')
plt.savefig('josephus_rec')
plt.show()