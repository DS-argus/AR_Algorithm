import string
import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

L = int(input())
s = input().rstrip()

r = 31
M = 1_234_567_891

order = {char: idx + 1 for idx, char in enumerate(string.ascii_lowercase)}

hash = 0
for i in range(L):
    hash += r**i * order[s[i]]

print(hash % M)
