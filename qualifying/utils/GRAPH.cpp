#include <vector>
#include <limits>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

enum { 
    INFTY = numeric_limits<int>::max()
    // INFTY = 2147483647
};  

enum Color {
    WHITE,
    GRAY,
    BLACK
};

struct Vertex {
    int id;

    // BFS properties
    Color color;
    int discovery;
    Vertex* parent;

    // DFS properties
    int finish;
};

// adjacenty list representation (Figure 22.1 (b) of CLRS 3rd ed.)
struct Graph {
    vector<Vertex> vertices;
    vector< vector<Vertex*> > adjacent;
};    

// pre-condition: graph of vertices with unitialized BFS properties
void breadth_first_search(Graph& G, Vertex* s)
{       
    for (auto& v: G.vertices){
        if (v.id == s->id) continue;
        v.color = WHITE;
        v.discovery = INFTY;
        v.parent = nullptr;
    }
    s->color = GRAY;
    s->discovery = 0;
    s->parent = nullptr;    
    queue<Vertex*> q;
    q.push(s);    
    while (!q.empty()) {
        auto u = q.front();
        q.pop();    
        for (auto v: G.adjacent[u->id]) {
            if (v->color == WHITE) {
                v->color = GRAY;
                v->discovery = u->discovery + 1;
                v->parent = u;
                q.push(v);
            }
        }
        u->color = BLACK;
    }
}

void depth_first_search_visit(Graph& G, Vertex* u, int& time, stack<Vertex*>& sorted_vertices) {
    u->color = GRAY;
    u->discovery = time++;
    for (auto v : G.adjacent[u->id]) {
        if (v->color == WHITE) {
            v->parent = u;
            depth_first_search_visit(G, v, time, sorted_vertices);
        }
    }
    u->color = BLACK;
    u->finish = time++;
    sorted_vertices.push(u); // Push the vertex to stack when done with it
}

void depth_first_search(Graph& G, stack<Vertex*>& sorted_vertices) {
    int time = 0; // Initialize time
    for (auto& u : G.vertices) {
        u.color = WHITE;
        u.parent = nullptr;
    }
    
    for (auto& u : G.vertices) {
        if (u.color == WHITE)
            depth_first_search_visit(G, &u, time, sorted_vertices);
    }
}

void topological_sort(Graph& G) {
    stack<Vertex*> sorted_vertices;
    depth_first_search(G, sorted_vertices);
    
    // Print sorted vertices
    cout << "Topological Sort Order:\n";
    while (!sorted_vertices.empty()) {
        cout << sorted_vertices.top()->id << " ";
        sorted_vertices.pop();
    }
    cout << endl;
}

Graph transpose_graph(const Graph& G) {
    Graph transposed_G;
    transposed_G.vertices.resize(G.vertices.size());
    transposed_G.adjacent.resize(G.vertices.size());
    
    // Transpose edges
    for (int i = 0; i < G.vertices.size(); ++i) {
        for (auto v : G.adjacent[i]) {
            transposed_G.adjacent[v->id].push_back(&transposed_G.vertices[i]);
        }
    }
    
    // Initialize vertices
    for (int i = 0; i < G.vertices.size(); ++i) {
        transposed_G.vertices[i].id = i;
        transposed_G.vertices[i].color = WHITE; // Set color to WHITE
        transposed_G.vertices[i].parent = nullptr; // Set parent to nullptr
    }
    
    return transposed_G;
}

void dfs_scc_visit(Graph& G_transposed, Vertex* u, vector<int>& scc_result, int scc_id) {
    u->color = GRAY;
    scc_result[u->id] = scc_id;
    for (auto v : G_transposed.adjacent[u->id]) {
        if (v->color == WHITE) {
            dfs_scc_visit(G_transposed, v, scc_result, scc_id);
        }
    }
}

vector<int> strongly_connected_components(Graph& G) {
    // Perform DFS to get finishing times
    stack<Vertex*> sorted_vertices;
    depth_first_search(G, sorted_vertices);
    
    // Reset all vertices color to WHITE for the second DFS
    for (auto& u : G.vertices) {
        u.color = WHITE;
    }
    
    // Transpose the graph
    Graph G_transposed = transpose_graph(G);
    
    // Second DFS to find SCCs
    vector<int> scc_result(G.vertices.size(), -1);
    int scc_id = 0;
    while (!sorted_vertices.empty()) {
        Vertex* u = sorted_vertices.top();
        sorted_vertices.pop();
        if (G_transposed.vertices[u->id].color == WHITE) { // Use transposed graph's vertex color
            dfs_scc_visit(G_transposed, &G_transposed.vertices[u->id], scc_result, scc_id);
            scc_id++;
        }
    }
    
    return scc_result;
}

int main() {
    Graph G;
    int numVertices = 8;

    // Initialize vertices
    for (int i = 0; i < numVertices; ++i) {
        Vertex v;
        v.id = i;
        G.vertices.push_back(v);
    }

    // Initialize adjacency list
    G.adjacent.resize(numVertices);

    // Modify adjacency list according to your graph connections
    G.adjacent[0].push_back(&G.vertices[1]);
    G.adjacent[1].push_back(&G.vertices[2]);
    G.adjacent[1].push_back(&G.vertices[4]);
    G.adjacent[1].push_back(&G.vertices[5]);
    G.adjacent[2].push_back(&G.vertices[3]);
    G.adjacent[2].push_back(&G.vertices[6]);
    G.adjacent[3].push_back(&G.vertices[2]);
    G.adjacent[3].push_back(&G.vertices[7]);
    G.adjacent[4].push_back(&G.vertices[0]);
    G.adjacent[4].push_back(&G.vertices[5]);
    G.adjacent[5].push_back(&G.vertices[6]);
    G.adjacent[6].push_back(&G.vertices[5]);
    G.adjacent[6].push_back(&G.vertices[7]);
    G.adjacent[7].push_back(&G.vertices[7]);

    // Perform BFS
    std::cout << "Breadth First Search\n";
    breadth_first_search(G, &G.vertices[0]); // Start BFS from vertex 0
    // Display BFS properties of vertices
    for (const auto& v : G.vertices) {
        std::cout << "Vertex " << v.id << ": Discovery time = " << v.discovery << std::endl;
    }

    // Perform DFS
    std::cout << "\nDepth First Search\n";
    std::stack<Vertex*> sorted_vertices_dfs;
    depth_first_search(G, sorted_vertices_dfs);
    // Display DFS properties of vertices
    for (const auto& v : G.vertices) {
        std::cout << "Vertex " << v.id << ": Finish time = " << v.finish << std::endl;
    }

    // Perform Topological Sort
    std::cout << "\nTopological Sort\n";
    topological_sort(G);

    vector<int> scc_result = strongly_connected_components(G);

    cout << "Strongly Connected Components:\n";
    for (int i = 0; i < scc_result.size(); ++i) {
        cout << "Vertex " << i << " belongs to SCC " << scc_result[i] << endl;
    }

    return 0;
}