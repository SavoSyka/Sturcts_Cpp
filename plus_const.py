from matplotlib import pyplot as plt
import numpy as np
am_of_ells = [100 ,228 ,400 ,1337 ,1600 ,3200 ,5000 ,7000 ,10000 ,15000 ,20000 ,25000 ,35000 ,45000 ,60000 ,75000 ,95000 ,115000 ,140000 ,165000 ,195000 ,225000 ,250000 ,295000 ,335000 ,375000 ,420000 ,465000 ,499999 ,510000 ,]
time = [11 ,16 ,18 ,42 ,27 ,103 ,110 ,172 ,431 ,650 ,1593 ,1437 ,4423 ,3786 ,12553 ,12562 ,21213 ,49538 ,42830 ,86504 ,99990 ,137988 ,115667 ,165208 ,205181 ,319689 ,392622 ,467518 ,564116 ,557386 ,]
plt.grid()
plt.plot(am_of_ells, time, '.')
plt.savefig('plus_const')
plt.show()