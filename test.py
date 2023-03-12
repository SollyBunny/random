#!/usr/bin/env python3
import subprocess

size = 6
out = [0] * size

for i in range(1000):
    out[int(subprocess.check_output(["./random", str(size)]))] += 1

for i in range(size):
    print("%s: %s" % (i, out[i]))
