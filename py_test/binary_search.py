

import matplotlib.pyplot as plt
import numpy as np
import math

x = np.arange(1, 100)
y1 = x
y2 = [math.log(i, 2) for i in x]


print(y2)

plt.plot(x, y1)
plt.plot(x, y2)
# plt.yscale('log')

plt.show()	
