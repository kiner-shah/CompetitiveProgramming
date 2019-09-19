#!/bin/python

import sys
import re

def patternCount(s):
    # Complete this function
    l = re.findall(r'(?=10+1)', s)
    return len(l)

q = int(raw_input().strip())
for a0 in xrange(q):
    s = raw_input().strip()
    result = patternCount(s)
    print(result)
