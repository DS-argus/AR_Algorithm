import sys

input = sys.stdin.readline

N, K = map(int, input().split())


class Node:
    def __init__(self, n):
        self.val = n
        self.next = None

    def print(self):
        visit = [self.val]

        n = self.next
        while not n.val in visit:
            visit.append(n.val)
            n = n.next

        print(visit)


def create_circle(nums: list[int]) -> "Node":
    prev = Node(0)
    nodes = [Node(num) for num in nums]

    for i in range(1, len(nums)):
        nodes[i - 1].next = nodes[i]

    nodes[-1].next = nodes[0]
    prev.next = nodes[0]

    return prev


def move_and_remove(circle, K) -> tuple["Node", int]:
    k = 0
    while k < K:
        cnt = circle
        circle = cnt.next
        k += 1

    # remove
    out = circle.val
    cnt.next = circle.next

    prev = Node(0)
    prev.next = circle.next
    return prev, out


remain = list(range(1, N + 1))

circle = create_circle(remain)
removed = []
while len(removed) < N:
    circle, out = move_and_remove(circle, K)
    removed.append(out)

result = ", ".join(map(str, removed))

print(f"<{result}>")
