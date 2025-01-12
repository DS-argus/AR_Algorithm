import sys

input = sys.stdin.readline
INF = sys.maxsize

N = int(input())

q = list()

for _ in range(N):
    command = input().split()
    INST = command[0]
    num = int(command[1]) if len(command) > 1 else None
    if INST == "push":
        q.append(num)

    elif INST == "pop":
        if q:
            print(q.pop(0))
        else:
            print(-1)

    elif INST == "size":
        print(len(q))

    elif INST == "empty":
        print(int(not q))

    elif INST == "front":
        val = q[0] if q else -1
        print(val)

    elif INST == "back":
        val = q[-1] if q else -1
        print(val)
