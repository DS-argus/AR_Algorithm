import sys

input = sys.stdin.readline
INF = sys.maxsize

M = int(input())
state = {k: 0 for k in range(1, 21)}

for _ in range(M):
    command = input().strip().split()
    inst = command[0]
    num = int(command[1]) if len(command) > 1 else None

    if inst == "add":
        state[num] = 1

    elif inst == "remove":
        state[num] = 0

    elif inst == "check":
        print(int(state[num]))

    elif inst == "toggle":
        state[num] = (state[num] + 1) % 2

    elif inst == "all":
        for k in state.keys():
            state[k] = 1

    elif inst == "empty":
        for k in state.keys():
            state[k] = 0

    else:
        continue
