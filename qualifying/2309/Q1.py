class GNode:

    def __init__(self, id, color="W", d=0, p=None) -> None:
        self.id = id
        self.color = color
        self.distance = d
        self.parent = p
    
    def __str__(self) -> str:
        return self.id
    
# def dfs_all_paths(G: dict, start: GNode) -> list:
#     all_paths = []  # Store all paths
#     stack = [(start, [start.id])]  # Stack stores tuples of (node, current path)

#     while stack:
#         (node, path) = stack.pop()
#         for neighbor in G[node]:
#             if neighbor.id not in path:  # Avoid cycles by checking if neighbor is already in path
#                 new_path = path + [neighbor.id]
#                 stack.append((neighbor, new_path))
#                 # If neighbor has no further unvisited neighbors, consider it a leaf node and save the path
#                 if all(n.id in path for n in G[neighbor]):
#                     all_paths.append(new_path)
#             elif len(G[node]) == 1:  # If this node has only one neighbor and it's already in path, it's an end node
#                 all_paths.append(path)

#     return all_paths

def dfs_all_paths(G: dict, start: GNode) -> list[list]:
    """
    Stack을 이용한 DFS로 모든 Path return
    """
    all_paths = []  # Store all paths
    stack = [(start, [start.id])]  # Stack stores tuples of (node, current path)

    while stack:
        (node, path) = stack.pop()

        if all(n.id in path for n in G[node]):
            all_paths.append(path)

        for neighbor in G[node]:
            if neighbor.id not in path:  # Avoid cycles by checking if neighbor is already in path
                new_path = path + [neighbor.id]
                stack.append((neighbor, new_path))
            
            
    return all_paths


def bfs(G: dict, start: GNode) -> list:
    visited = set()  # To keep track of visited nodes
    queue = [start]  # Initialize the queue with the start node
    visited.add(start.id)  # Mark the start node as visited
    
    result = []  # To store the order of visited nodes

    while queue:
        node = queue.pop(0)  # Remove and return the first node from the list, acting as a queue
        result.append(node.id)  # Process the current node
        
        # Iterate through the neighbors of the current node
        for neighbor in G[node]:
            if neighbor.id not in visited:
                visited.add(neighbor.id)  # Mark the neighbor as visited
                queue.append(neighbor)  # Add the neighbor to the queue for later visitation
    
    return result

def run_DFS(G: dict, head: GNode) -> list:
    visited = set()
    stack = []

    stack.append(head)

    while stack:

        node = stack.pop()
        visited.add(node.id)

        for neighbor in G[node]:
            if neighbor.id not in visited:
                stack.append(neighbor)
    
    return visited


def find_root_vertices(G: dict) -> list:
    result = []
    for node in G.keys():
        # DFS 풀이
        paths = dfs_all_paths(G, node)
        print(node, paths)
        visit = set(sum(paths, []))
        
        # BFS 풀이
        # paths = bfs(G, node)
        # visit = paths


        if len(visit) == len(G.keys()): result.append(node.id)

    return result


if __name__ == "__main__":
    A, B, C = GNode('A'), GNode('B'), GNode('C')
    D, E, F = GNode('D'), GNode('E'), GNode('F')

    G = dict()

    G[A], G[B], G[C] = [C, D], [A, E], [B, D]
    G[D], G[E], G[F] = [F], [F], []


    print(find_root_vertices(G))


    G[A], G[B], G[C] = [D], [E], [B, D]
    G[D], G[E], G[F] = [F], [F], []

    print(find_root_vertices(G))