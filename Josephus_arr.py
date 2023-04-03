from matplotlib import pyplot as plt
import numpy as np
am_of_ells = [100 ,228 ,400 ,1337 ,1600 ,3200 ,5000 ,7000 ,10000 ,15000 ,20000 ,25000 ,35000 ,45000 ,60000 ,75000 ,95000 ,]
time = [6 ,19 ,57 ,616 ,877 ,3495 ,8511 ,16767 ,36678 ,81695 ,140701 ,219360 ,436393 ,737583 ,1298966 ,2033584 ,3289134 ,]
plt.grid()
plt.plot(am_of_ells, time, '.')
plt.savefig('josephus_arr')
plt.show()