import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    parents = {}

    for _ in range(N - 1):
        pa, ch = map(int, input().split())
        parents[ch] = pa

    A, B = map(int, input().split())

    # A의 조상들을 set에 저장
    ancestors = set()
    while A in parents:
        ancestors.add(A)
        A = parents[A]
    ancestors.add(A)  # 루트도 포함

    # B를 위로 타고 올라가면서 A의 조상 중 하나와 처음 만나는 지점이 LCA
    while B not in ancestors:
        B = parents[B]

    print(B)