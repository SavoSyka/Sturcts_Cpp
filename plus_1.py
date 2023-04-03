from matplotlib import pyplot as plt
import numpy as np
am_of_ells = [100 ,228 ,400 ,1337 ,1600 ,3200 ,5000 ,7000 ,10000 ,15000 ,20000 ,25000 ,35000 ,45000 ,60000 ,75000 ,95000 ,]
time = [76 ,247 ,551 ,4227 ,6141 ,23331 ,56766 ,96009 ,171367 ,414706 ,672222 ,987386 ,2210641 ,3473161 ,6110284 ,9792950 ,15958800 ,]
plt.grid()
plt.plot(am_of_ells, time, '.')
plt.savefig('plus_1')
plt.show()
