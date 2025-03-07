import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N = int(input())


def hanoi(n: int, fr: int, to: int, left: int) -> int:
    assert fr != to and fr != left and to != left

    if n == 1:
        actions.append((fr, to))
        return 1

    result = (
        hanoi(n - 1, fr, left, to) + hanoi(1, fr, to, left) + hanoi(n - 1, left, to, fr)
    )

    return result


actions = []

print(hanoi(N, 1, 3, 2))
for fr, to in actions:
    print(fr, to)

