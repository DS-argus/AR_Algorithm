import sys

input = sys.stdin.readline
inf = sys.maxsize

n = int(input())
inputs = list(map(int, input().split()))
temp = inputs[:]
temp = list(set(temp))
temp.sort()

# [-10 -9 2 4 4] => [0 1 2 3 3]
# [999 999 999 1000 1000 1000] => [0 0 0 1 1 1]

index_dict = {k: i for i, k in enumerate(temp)}

result = [index_dict[num] for num in inputs]

print(*result)
