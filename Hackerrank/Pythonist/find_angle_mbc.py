# Enter your code here. Read input from STDIN. Print output to STDOUT
import math
x=int(raw_input())
y=int(raw_input())
h=math.hypot(x,y)
v=math.asin(x/h)*180/math.pi
if v<math.floor(v)+0.5:
    print int(math.floor(v))
else:
    print int(math.ceil(v))
