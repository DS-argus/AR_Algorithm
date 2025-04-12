import heapq
import sys
from collections import defaultdict, deque

input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))


def binary_search_left(arr, target):
    left, right = 0, len(arr)

    while left < right:
        mid = (left + right) // 2

        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid

    return left


tail = []

for i in range(N):
    idx = binary_search_left(tail, arr[i])

    if idx == len(tail):
        tail.append(arr[i])
    else:
        tail[idx] = arr[i]

print(len(tail))
