import sys

input = sys.stdin.readline
# input 받는 법 : sys.stdin.readline()

from collections import deque

N = int(input())

q = deque()
for i in range(1, N + 1):
    q.append(i)

while len(q) > 1:
    q.popleft()
    q.append(q.popleft())

print(q.popleft())
