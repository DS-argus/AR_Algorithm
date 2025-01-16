import sys

input = sys.stdin.readline

N, M = map(int, input().split())
trees = list(map(int, input().split()))


def get_amount(h: int) -> int:
    """높이 h에서 자르고 남은 나무 길이의 총합 계산"""
    return sum(tree - h for tree in trees if tree > h)


# 이분 탐색으로 절단 높이 h를 찾는다
start, end = 0, max(trees)
result = 0

while start <= end:
    mid = (start + end) // 2
    amount = get_amount(mid)

    if amount >= M:  # 필요한 나무 길이보다 많거나 같은 경우
        result = mid  # 현재 높이를 저장
        start = mid + 1  # 더 높은 절단 높이를 탐색
    else:  # 필요한 나무 길이보다 적은 경우
        end = mid - 1

print(result)
