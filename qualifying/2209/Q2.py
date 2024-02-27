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
    # a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    # G = dict()
    # G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]

    # print(paths(G,a,c))


    # Create nodes
    # a, b, c, d, e, f = GNode('a'), GNode('b'), GNode('c'), GNode('d'), GNode('e'), GNode('f')

    # # Define the graph
    # G = dict()
    # G[a], G[b], G[c], G[d], G[e], G[f] = [b, d], [c, e], [f], [e], [f], []

    # # Print the paths from 'a' to 'f'
    # print(paths(G, a, f))


    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    G = dict()
    G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]

    print(paths(G, a, c))

    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    e, f = GNode('e'), GNode('f')
    G = dict()
    G[a], G[b], G[c], G[d] = [b, c, f], [d], [], [c, f]
    G[e], G[f] = [c], [c, e]

    print(paths(G, a, c))            

    # a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    # G = dict()
    # G[a], G[b], G[c], G[d] = [b, c], [d, c], [], [c, b]

    # print(paths(G, a, c))

    # a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    # G = dict()
    # G[a], G[b], G[c], G[d] = [b, d], [d, c], [], [c, b]

    # print(paths(G, a, c))