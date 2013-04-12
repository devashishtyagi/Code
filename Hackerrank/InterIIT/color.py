import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import math
from sklearn import linear_model
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# read file
n = int(input())
print n, "lines to read"
skin = []
skinx = []
skiny = []
skinz = []
nonskinx = []
nonskiny = []
nonskinz = []
for i in xrange(n):
	line = raw_input()
	listinput = line.split(' ')
	r = int(listinput[0])
	g = int(listinput[1])
	b = int(listinput[2])
	a = int(listinput[3])
	if (a == 1):
		skinx.append(float(r)); skiny.append(float(r)); skinz.append(float(b));
		skin.append([r, g, b])
	else:
		nonskinx.append(float(r)); nonskiny.append(float(r)); nonskinz.append(float(b));

print "Reading done."

ax.scatter(skinx, skiny, skinz, c = 'r', marker = 'o')
#ax.scatter(nonskinx, nonskiny, nonskinz, c = 'b', marker = '^')

ax.set_xlabel('Red')
ax.set_ylabel('Blue')
ax.set_zlabel('Green')

medianx = 0.0; mediany = 0.0; medianz = 0.0;
devx = 0.0; devy = 0.0; devz = 0.0;

for i in xrange(len(skinx)):
	medianx += skinx[i]
	mediany += skiny[i]
	medianz += skinz[i]

medianx = medianx/float(len(skinx))
mediany = mediany/float(len(skinx))
medianz = medianz/float(len(skinx))
print medianx, mediany, medianz

for i in xrange(len(skinx)):
	devx += (skinx[i] - medianx)**2
	devy += (skiny[i] - mediany)**2
	devz += (skinz[i] - medianz)**2

devx = devx/float(len(skinx))
devy = devy/float(len(skinx))
devz = devz/float(len(skinx))

devx = math.sqrt(devx)
devy = math.sqrt(devy)
devz = math.sqrt(devz)

print devx, devy, devz

# train a linear classifier
clf = linear_model.LinearRegression()
Y = range(len(skin))
clf.fit(np.array(skin), np.array(Y))
print clf.coef_
print clf.intercept_

plt.show()