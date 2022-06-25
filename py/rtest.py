import math


r = 1


x=-1
while x <= 1:
    y = math.sqrt(r*r - x*x)
    print(y, -y)
    x+=0.1