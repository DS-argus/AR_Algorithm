import sys
input = sys.stdin.readline

N = int(input())
if N == 0:
    print(0)
    exit()

x, y = 0, 1
MOD = 1_000_000_007

for _ in range(2, N + 1):
    y, x = (y + x) % MOD, y

print(y)