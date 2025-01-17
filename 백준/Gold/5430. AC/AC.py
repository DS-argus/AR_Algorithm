import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    p = input().strip()
    N = int(input())
    L = input().strip()
    if len(L) > 2:
        L = list(map(int, L[1:-1].split(",")))
    else:
        L = []

    flag = False

    R_cnt = 0
    for func in p:
        if func == "R":
            R_cnt += 1
        elif func == "D":
            if len(L):
                if R_cnt % 2 == 0:
                    L.pop(0)
                else:
                    L.pop()
            else:
                flag = True
                break
    if flag:
        print("error")
        continue

    if R_cnt % 2 == 1:
        L.reverse()
    result = ",".join(map(str, L))
    print(f"[{result}]")
