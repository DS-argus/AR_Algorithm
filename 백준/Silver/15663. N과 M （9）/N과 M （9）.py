import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N, M = map(int, input().split())
numbers = sorted(map(int, input().split()))  # 입력을 정렬하여 중복 방지

def backtrack(ans, used):
    if len(ans) == M:
        print(" ".join(map(str, ans)))
        return

    prev = -1
    for i in range(N):
        if not used[i] and numbers[i] != prev:
            used[i] = True
            backtrack(ans + [numbers[i]], used)
            used[i] = False
            prev = numbers[i]

used = [False] * N
backtrack([], used)