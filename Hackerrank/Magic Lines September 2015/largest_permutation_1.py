#!/usr/bin/env python
import sys


line = sys.stdin.readline()
tokens = line.split(" ")
N = int(tokens[0])
K = int(tokens[1])

line = sys.stdin.readline()
tokens = line.split(" ")


original = [int(elem) for elem in tokens]


sorted = list(original)

sorted.sort(reverse =True)

def permute(list,i1,i2):
      tmp = list[i1]
      list[i1] = list[i2]
      list[i2] = tmp


current = 0
while (K > 0 and current< (len(sorted)-1)):
   if(original[current] <> sorted[current]):
      permute(original,current,original.index(sorted[current]))
      K-=1
   current+=1
      

print ' '.join(map(str,original))
