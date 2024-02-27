class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.distance = d
        self.parent = p
    
    def __str__(self):
        return self.id

def bfs(G: dict, s: "GNode"):

    depth_dict = dict()
    
    q = list()
    q.append(s)
    V_list = [s.id]
    
    while len(q) > 0 :
        cnt = q[0]
        q.remove(cnt)
        
        # if cnt.distance not in depth_dict.keys():
        #     depth_dict[cnt.distance] = [cnt.id]
        # else:      
        #     depth_dict[cnt.distance].append(cnt.id)
        
        depth_dict.setdefault(cnt.distance, []).append(cnt.id)

        cnt.color = 'B'

        for neighbor in G[cnt]:
            if neighbor.color == "W" and neighbor.id not in V_list:
                neighbor.distance = cnt.distance+1
                q.append(neighbor)
                V_list.append(neighbor.id)

    return depth_dict

def level_partition(G,s):
    return list(bfs(G, s).values())

if __name__ == "__main__":
    # r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    # w, x, y = GNode('w'), GNode('x'), GNode('y')
    # G = dict()
    # G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
    # G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u] 

    # print(level_partition(G, s))

    r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    w, x, y = GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
    G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]

    # bfs(G, s)

    # print(s.distance)
    # print(r.distance, w.distance)
    # print(v.distance, t.distance, x.distance)
    # print(u.distance, y.distance)

    print(level_partition(G, s))
    # print(s.distance)
    # print(r.distance, w.distance)
    # print(v.distance, t.distance, x.distance)
    # print(u.distance, y.distance)