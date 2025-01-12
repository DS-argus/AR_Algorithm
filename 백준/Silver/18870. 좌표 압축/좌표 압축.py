import sys

input = sys.stdin.readline
inf = sys.maxsize

n = int(input())
inputs = list(map(int, input().split()))
temp = sorted(set(inputs))

index_dict = {k: i for i, k in enumerate(temp)}

result = [index_dict[num] for num in inputs]

print(*result)
