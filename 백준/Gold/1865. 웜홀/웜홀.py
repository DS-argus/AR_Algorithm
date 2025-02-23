import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline


def bellman_ford(start, N, EDGES):
    COST = [sys.maxsize] * (N + 1)  # 가상의 노드 포함
    COST[start] = 0  # 가상의 노드에서 시작

    # (N)번 반복 -> 최단 거리 갱신
    for _ in range(N):
        updated = False
        for u, v, cost in EDGES:
            if COST[u] != sys.maxsize and COST[v] > COST[u] + cost:
                COST[v] = COST[u] + cost
                updated = True

        # 더 이상 갱신할 것이 없으면 조기 종료 (Early Stopping)
        if not updated:
            break

    # (N번째) 한 번 더 확인 → 음수 사이클 존재 여부 판단
    for u, v, cost in EDGES:
        if COST[u] != sys.maxsize and COST[v] > COST[u] + cost:
            return True  # 음수 사이클 존재

    return False  # 음수 사이클 없음


TC = int(input())
for _ in range(TC):
    N, M, W = map(int, input().split())

    # ✅ defaultdict 대신 일반 딕셔너리 사용하여 중복 간선 최소 값 유지
    EDGES = defaultdict(lambda: float('inf'))

    # 🚀 도로 간선 추가
    for _ in range(M):
        u, v, w = map(int, input().split())
        EDGES[(u, v)] = min(EDGES[(u, v)], w)
        EDGES[(v, u)] = min(EDGES[(v, u)], w)  # 무방향 간선

    # 🚀 웜홀 간선 추가 (음수 가중치)
    for _ in range(W):
        u, v, w = map(int, input().split())
        EDGES[(u, v)] = min(EDGES[(u, v)], -w)  # 단방향 간선

    # ✅ 리스트 형태로 변환하여 Bellman-Ford에서 사용
    EDGE_LIST = [(u, v, w) for (u, v), w in EDGES.items()]

    # ✅ 가상의 노드(0번 노드) 추가 (모든 노드와 연결)
    for i in range(1, N + 1):
        EDGE_LIST.append((0, i, 0))  # 모든 노드에 가중치 0의 간선 추가

    # ✅ Bellman-Ford 한 번만 실행
    if bellman_ford(0, N, EDGE_LIST):  # 가상의 노드(0)에서 시작
        print("YES")
    else:
        print("NO")