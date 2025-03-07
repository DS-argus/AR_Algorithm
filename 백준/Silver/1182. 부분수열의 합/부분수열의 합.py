import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, S = map(int, input().split())
numbers = list(map(int, input().split()))

def recursive(idx: int, s: int) -> int:

    if idx == N:
        return 1 if s == S else 0  

    return recursive(idx + 1, s) + recursive(idx + 1, s + numbers[idx])

# 부분합이 0인 경우 공집합 제외 처리
result = recursive(0, 0) - (1 if S == 0 else 0)
print(result)