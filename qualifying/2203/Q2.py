class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.distance = d
        self.parent = p
    
    def __str__(self):
        return self.id

def bfs(G: dict, s: GNode):

    depth_dict = dict()
    q = [s]
    used = set(s.id)
    while q:
        cnt =  q.pop(0)
        depth_dict.setdefault(cnt.distance, []).append(cnt.id)

        cnt.color = 'B'

        for neighbor in G[cnt]:
            if neighbor.color == "W" and neighbor.id not in used:
                neighbor.distance = max(cnt.distance+1, neighbor.distance)
                q.append(neighbor)
                used.add(neighbor.id)

    return depth_dict

def level_partition(G,s):
    return list(bfs(G, s).values())

if __name__ == "__main__":
    r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    w, x, y = GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
    G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u] 

    print(level_partition(G, s))