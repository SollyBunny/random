#!/usr/bin/env python3
import subprocess 
a = 0
b = 10
n = 1000
out = {}
for i in range(min(a, b), max(a, b) + 1):
    out[i] = 0
for i in range(n):
    m = subprocess.call(["./random", str(a), str(b)], stdout=subprocess.DEVNULL)
    out[m] += 1
print(out)
print(sum(out.values()) / abs(a - b))
    
