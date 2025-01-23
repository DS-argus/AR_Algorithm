import sys

input = sys.stdin.readline

from collections import defaultdict, deque

N = int(input())
Tree = defaultdict(list, [])

for _ in range(N):
    pa, lc, rc = input().split()

    Tree[pa].append(lc)
    Tree[pa].append(rc)


def traverse(Tree: dict, type: str) -> None:
    assert type in ["pre", "in", "post"]

    def dfs(node: str, result: list, type: str):

        if type == "pre":
            result.append(node)
        lc, rc = Tree[node]
        if lc != ".":
            dfs(lc, result, type)

        if type == "in":
            result.append(node)

        if rc != ".":
            dfs(rc, result, type)

        if type == "post":
            result.append(node)

    result = []
    dfs("A", result, type)
    print("".join(result))


traverse(Tree, "pre")
traverse(Tree, "in")
traverse(Tree, "post")
