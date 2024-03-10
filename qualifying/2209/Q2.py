class GNode:
    def __init__(self, id):
        self.id = id
    def __str__(self):
        return self.id

# acyclic directed graph니까 visit했는지와 paths에서 for loop으로 dfshelp 돌릴 필요 없음
def paths(G, a, c):

    result = []
    path = []
    dfs_help(G, a, c, path, result)

    return result

def dfs_help(G, a, c, path, result):

    path.append(a.id)

    if path[-1] == c.id:
        result.append(path)
        return
    
    for neighbor in G[a]:
        dfs_help(G, neighbor, c, path.copy(), result)
        

if __name__ == "__main__":
    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    G = dict()
    G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]

    print(paths(G,a,c))