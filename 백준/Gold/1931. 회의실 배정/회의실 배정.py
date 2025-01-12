import sys

input = sys.stdin.readline
INF = sys.maxsize

N = int(input())
TIME = [tuple(map(int, input().split())) for _ in range(N)]
TIME.sort(key=lambda x: (x[1], x[0]))

end_time, count = 0, 0

for start, end in TIME:
    if start >= end_time:
        end_time = end
        count += 1

print(count)
