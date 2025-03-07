import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N = int(input())


def hanoi(n: int, fr: int, to: int, left: int) -> None:

    if n == 1:
        print(fr, to)
        return

    hanoi(n - 1, fr, left, to)
    hanoi(1, fr, to, left)
    hanoi(n - 1, left, to, fr)


print(2**N - 1)
if N <= 20:
    hanoi(N, 1, 3, 2)
