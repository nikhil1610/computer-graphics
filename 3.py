# Dhruv Tewari
# COE - 2
# Roll No - 2019UCO1624
# Computer Graphics

import numpy as np
import matplotlib.pyplot as plt
x_cent = 0
y_cent = 0 
r=5

x_quad1 = []
y_quad1 = []
decor = []
x_init = 0
y_init = r
decision_parameter = 3 - 2 * r
x = x_init
y = y_init
p = decision_parameter
while(x < y):
    x_quad1.append(x)
    y_quad1.append(y)
    if p < 0:
        x += 1
        p += 4 * x + 6
    else:
        x += 1
        y -= 1
        p += 4 * (x - y) - 10
x_quad1.append(x)
y_quad1.append(y)
for i in range(len(x_quad1)):
    x_quad1.append(y_quad1[i])
    y_quad1.append(x_quad1[i])
    
x_quad2 = [(x_cent - x) for x in x_quad1]
y_quad2 = [(y_cent + y) for y in y_quad1]
x_quad3 = [(x_cent - x) for x in x_quad1]
y_quad3 = [(y_cent - y) for y in y_quad1]
x_quad4 = [(x_cent + x) for x in x_quad1]
y_quad4 = [(y_cent - y) for y in y_quad1]
x_quad1 = [(x_cent + x) for x in x_quad1]
y_quad1 = [(y_cent + y) for y in y_quad1]
x_quad1 = np.array(x_quad1, dtype = int)
y_quad1 = np.array(y_quad1, dtype = int)
x_quad2 = np.array(x_quad2, dtype = int)
y_quad2 = np.array(y_quad2, dtype = int)
x_quad3 = np.array(x_quad3, dtype = int)
y_quad3 = np.array(y_quad3, dtype = int)
x_quad4 = np.array(x_quad4, dtype = int)
y_quad4 = np.array(y_quad4, dtype = int)
print(np.vstack((x_quad1, y_quad1, x_quad2, y_quad2, x_quad3, y_quad3, x_quad4, y_quad4)).T)
fig = plt.figure()
ax = fig.add_subplot(111)
plt.plot(x_quad1, y_quad1, x_quad2, y_quad2, x_quad3, y_quad3, x_quad4, y_quad4)
ax.set_aspect('equal', adjustable='box')
plt.title("Bresenham Circle Drawing Algorithm")
plt.xlabel("x-axis")
plt.ylabel("y-axis")
plt.show()

