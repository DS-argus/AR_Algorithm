import sys

input = sys.stdin.readline

N, M = map(int, input().split())
known = list(map(int, input().split()))
PARTIES = [list(map(int, input().split())) for _ in range(M)]


if known[0] == 0:
    print(M)
    exit()

KNOWN = list(range(N + 1))


def find(x):
    if KNOWN[x] != x:
        KNOWN[x] = find(KNOWN[x])

    return KNOWN[x]


def union(a, b):
    root_a = find(a)
    root_b = find(b)

    if root_a < root_b:
        KNOWN[root_b] = root_a
    else:
        KNOWN[root_a] = root_b


# for party in PARTIES:
#     for i in range(party[0] - 1):
#         union(party[i + 1], party[i + 2])

for party in PARTIES:
    rep = party[1]
    for parti in party[2:]:
        union(rep, parti)


known_group = {find(kn) for kn in known[1:]}

num = sum(all(find(p) not in known_group for p in party[1:]) for party in PARTIES)

print(num)
