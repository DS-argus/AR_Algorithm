import sys

input = sys.stdin.readline
# input 받는 법 : sys.stdin.readline()

from collections import defaultdict

N = int(input())
Ns = list(map(int, input().split(" ")))

min_Ns, max_Ns = min(Ns), max(Ns)
hash_table = defaultdict(int)

for n in Ns:
    hash_table[n] = 1
#
M = int(input())
Ms = list(map(int, input().split(" ")))

for m in Ms:
    print(hash_table[m])
