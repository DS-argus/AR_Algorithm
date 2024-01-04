import sys
import math
N = int(sys.stdin.readline().rstrip())

vals = []
dic = {}
total_sum = 0
max_freq = 0
mode_candidates = []

for _ in range(N):
    val = int(sys.stdin.readline().rstrip())
    vals.append(val)

    total_sum += val

    # Update the frequency dictionary
    dic[val] = dic.get(val, 0) + 1
    freq = dic[val]

    # Update mode candidates
    if freq > max_freq:
        max_freq = freq
        mode_candidates = [val]
    elif freq == max_freq and val not in mode_candidates:
        mode_candidates.append(val)

# Mean
mean = math.floor(total_sum / N + 0.5)
print(mean)

# Median
vals.sort()
median = vals[N // 2]
print(median)

# Mode
if len(mode_candidates) >= 2:
    mode_candidates.sort()
    mode = mode_candidates[1]
else:
    mode = mode_candidates[0]

print(mode)

# Range
value_range = max(vals) - min(vals)
print(value_range)

