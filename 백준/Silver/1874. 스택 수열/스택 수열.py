import sys

input = sys.stdin.readline
INF = sys.maxsize

from collections import deque

N = int(input())
orders = deque([int(input()) for _ in range(N)])

inputs = deque(range(1, N + 1))
stack = []
result = []
flag = False

while stack or inputs:
    if stack and stack[-1] == orders[0]:
        stack.pop()
        orders.popleft()
        result.append("-")

    elif inputs:
        stack.append(inputs.popleft())
        result.append("+")
    else:
        print("NO")
        exit()

print("\n".join(result))
