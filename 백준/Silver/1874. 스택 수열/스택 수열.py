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
    if not stack:
        stack.append(inputs[0])
        inputs.popleft()
        result.append("+")

    elif not inputs:
        # 실패
        if list(stack) != list(orders)[::-1]:
            flag = True
            break
        # 성공 : pop만 해주면 됨
        else:
            while stack:
                result.append("-")
                stack.pop()

    else:
        num = inputs[0]
        if stack[-1] < orders[0]:
            stack.append(num)
            inputs.popleft()
            result.append("+")

        elif stack[-1] == orders[0]:
            stack.pop()
            orders.popleft()
            result.append("-")

        else:
            flag = True
            break


if flag:
    print("NO")

else:
    for v in result:
        print(v)
