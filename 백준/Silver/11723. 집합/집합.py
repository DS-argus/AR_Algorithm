import sys

input = sys.stdin.readline
INF = sys.maxsize

M = int(input())
state = 0

for _ in range(M):
    command = input().strip().split()
    inst = command[0]
    num = int(command[1]) if len(command) > 1 else None

    if inst == "add":
        state |= 1 << num

    elif inst == "remove":
        state &= ~(1 << num)

    elif inst == "check":
        print(1 if (state & (1 << num)) else 0)

    elif inst == "toggle":
        state ^= 1 << num

    elif inst == "all":
        state = (1 << 21) - 1

    elif inst == "empty":
        state = 0

    else:
        continue
