class GNode:
    def __init__(self, id, color='W', d=-1, f=-1, p=None) -> None:
        self.id = id
        self.color = color
        self.d = d
        self.f = f
        self.parent = p

    def __str__(self) -> str:
        return self.id

def LexSmallest(G, t, v):

    stack = [(t, "")]
    paths = []
    
    # DFS part
    while stack:
        cnt, path = stack.pop()
        path += cnt.id

        if cnt == v:
            paths.append(path)
        
        for neighbor in G[cnt]:
            if neighbor.id not in path:
                stack.append((neighbor, path))

    if paths == []: return []

    for i in range(len(paths)):
        for j in range(i):
            if paths[i] < paths[j]:
                paths[i], paths[j] = paths[j], paths[i]
            
    return [s for s in paths[0]]



# def DFS(G, u, v):
#     path = []
#     result = []
#     DFS_help(G, u, v, path, result)

#     return result

# def DFS_help(G, s, t, path, result):

#     s.color = 'B'
#     path.append(s.id)

#     if s.id==t.id :
#         result.append(path)
#         return 
    
#     for neighbor in G[s]:
#         if neighbor.color == 'W':
#             DFS_help(G, neighbor, t, path.copy(), result)
#             neighbor.color = 'W'

# def LexSmallest(G, u, v):
#     all_paths = DFS(G, u, v)

#     if len(all_paths) == 0:
#         return all_paths

#     ans = all_paths[0]
#     for path in all_paths:
#         for i in range(len(ans)):
#             if ans[i] > path[i]:
#                 ans = path
#             else:
#                 ans = ans
            
#             break

#     return ans

if __name__ == "__main__":
    r, s, t, u = GNode('r'), GNode('s'), GNode('t'), GNode('u')
    v, w, x, y = GNode('v'), GNode('w'), GNode('x'), GNode('y')

    G = dict()
    G[r], G[w], G[t], G[u] = [w, v], [s, r, t], [s, x, w], [y]
    G[v], G[s], G[x], G[y] = [r], [w, t, x], [s, t], [u]

    print(f"Answer 1 : {LexSmallest(G, t, v)}")
    print(f"Answer 2 : {LexSmallest(G, u, u)}")
    print(f"Answer 3 : {LexSmallest(G, w, y)}")

    # print('a' > 'b')
    # print('a' < 'b')    #True
    # print('s' < 'x')    #True
    # print('s' > 'x')