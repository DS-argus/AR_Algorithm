#include <iostream>
#include <list>
#include <vector>

using namespace std;

enum Color
{
    WHITE,
    GRAY,
    BLACK
};


class di_graph {

    // undirected is 일부 of directed

    public:
        int n_vertex;
        // adjacency lists
        vector< vector<int> > edges;
        // const &: 데이터를 복사하지 않고 가져오되(&), 그 원본데이터를 변형시킬 수 없다(const)
        // vector< vector<int> > edges(vertex개수, 각 vector<int> init)
        di_graph(const int& aN_vertex, const vector<vector<int>>& aEdges): n_vertex(aN_vertex), edges(aN_vertex, vector<int>(0)) {
            for(const vector<int>& e: aEdges) {
                edges[e[0]].push_back(e[1]);
            }
        }
        void bfs(int s);

        void dfs(const vector<vector<int>>& G);
        void dfs_help(const vector<vector<int>>& G, int& time, Color color[], int d[], int f[], int p[], int v);

        void topological_sort(void);
        void dfs_for_topological_sort(const vector<vector<int>>& G);
        void dfs_help_for_topological_sort(const vector<vector<int>>& G, int& time, Color color[], int d[], int f[], int p[], int u, vector<int>& order);

        void dfs_for_SCC(const vector<vector<int>>& G, int f[]);
        int find_max_f(int f[]);
        void dfs_G_T_for_SCC(const vector<vector<int>>& G_T, int f[]);
        void dfs_G_T_help_for_SCC(const vector<vector<int>>& G, Color color[], int u);
        void find_SCC(void);
        void visit(int);

};

void di_graph::visit(int v){
    cout << v << " ";
}

void di_graph::bfs(int s){

    int d[n_vertex];
    int p[n_vertex];
    Color color[n_vertex];

    for(int i = 0; i < n_vertex; i++){
        color[i] =  WHITE;
        d[i] = -1;
        p[i] = -1;
    }

    color[s] = GRAY;
    d[s] = 0;
    p[s] = -1;

    list<int> q;

    q.push_back(s);
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop_front();
        for (const int& v: edges[u]){
            if (color[v] == WHITE){
                color[v] = GRAY;
                d[v] = d[v] + 1;
                p[v] = u;
                q.push_back(v);
            }
        }
        color[u] = BLACK;
        visit(u);
    }
    cout << endl;
}

void di_graph::dfs(const vector<vector<int>>& G){
    Color color[n_vertex];
    int p[n_vertex];
    int d[n_vertex];
    int f[n_vertex];
    for(int i = 0; i < n_vertex; i++) {
        color[i] = WHITE;
        p[i] = -1;
        d[i] = 0;
        f[i] = 0;
    }
    int time = 0;
    for(int u = 0; u < n_vertex; u++) {
        if (color[u] == WHITE){
            dfs_help(G, time, color, d, f, p, u);
        }
    }
    for (int i = 0; i < n_vertex; i++) {
        cout << "vertex number: " << i << " d time: " << d[i] << " f time: " << f[i] << endl;

    }
}

void di_graph::dfs_help(const vector<vector<int>>& G, int& time, Color color[], int d[], int f[], int p[], int u) {
    time = time + 1;
    d[u] = time;
    color[u] = GRAY;
    for (const int& v: G[u]){
        if (color[v] == WHITE) {
            p[v] = u;
            dfs_help(G, time, color, d, f, p, v);
        }
    }
    time = time + 1;
    f[u] = time;
    color[u] = BLACK;
}

void di_graph::dfs_for_topological_sort(const vector<vector<int>>& G){
    vector<int> order(0);
    Color color[n_vertex];
    int p[n_vertex];
    int d[n_vertex];
    int f[n_vertex];
    for(int i = 0; i < n_vertex; i++) {
        color[i] = WHITE;
        p[i] = -1;
        d[i] = 0;
        f[i] = 0;
    }
    int time = 0;
    for(int u = 0; u < n_vertex; u++) {
        if (color[u] == WHITE){
            dfs_help_for_topological_sort(G, time, color, d, f, p, u, order);
        }
    }
    for(const int& v: order){
        cout << v << " " << d[v] << "/" << f[v] << endl;
    }
}

void di_graph::dfs_help_for_topological_sort(const vector<vector<int>>& G, int& time, Color color[], int d[], int f[], int p[], int u, vector<int>& order) {
    time = time + 1;
    d[u] = time;
    color[u] = GRAY;
    for (const int& v: G[u]){
        if (color[v] == WHITE) {
            p[v] = u;
            dfs_help_for_topological_sort(G, time, color, d, f, p, v, order);
        }
    }
    time = time + 1;
    f[u] = time;
    color[u] = BLACK;
    order.insert(order.begin(), u);
}

void di_graph::topological_sort(void) {
    dfs_for_topological_sort(edges);
}

void di_graph::dfs_for_SCC(const vector<vector<int>>& G, int f[]){
    // input 으로 f를 받음 나중에 써야해서
    Color color[n_vertex];
    int p[n_vertex];
    int d[n_vertex];
    for(int i = 0; i < n_vertex; i++) {
        color[i] = WHITE;
        p[i] = -1;
        d[i] = 0;
        f[i] = 0;
    }
    int time = 0;
    for(int u = 0; u < n_vertex; u++) {
        if (color[u] == WHITE){
            dfs_help(G, time, color, d, f, p, u);
        }
    }
}

int di_graph::find_max_f(int f[]){
    int max_index = 0;
    for (int i=0; i < n_vertex; i++) {
        if (f[i] > f[max_index]) {
            max_index = i;
        }
    }
    f[max_index] = 0;
    return max_index;
}

void di_graph::dfs_G_T_help_for_SCC(const vector<vector<int>>& G, Color color[], int u) {
    // DFS(G_T)에서 순서 정한 DFS할 떄 사용
    color[u] = GRAY;
    cout << u << " ";
    for (const int& v: G[u]){
        if (color[v] == WHITE) {
            dfs_G_T_help_for_SCC(G, color, v);
        }
    }
    color[u] = BLACK;
}

void di_graph::dfs_G_T_for_SCC(const vector<vector<int>>& G_T, int f[]){
    Color color[n_vertex];
    for(int i = 0; i < n_vertex; i++) {
        color[i] = WHITE;
    }
    int u;
    int count_SCC = 0;
    for(int i = 0; i < n_vertex; i++) {
        u = find_max_f(f);
        if (color[u] == WHITE){
            count_SCC++;
            cout<< "SCC " << count_SCC << ": ";
            dfs_G_T_help_for_SCC(G_T, color, u);
            cout << endl;
        }
    }
}

void di_graph::find_SCC(void) {
    // DFS(G)
    int f[n_vertex];
    dfs_for_SCC(edges, f);

    // create G_T
    vector<vector<int>> G_T(n_vertex, vector<int>(0));
    for(int i = 0; i < n_vertex; i++) {
        for (const int& j: edges[i]){
            G_T[j].push_back(i);
        }
    }

    dfs_G_T_for_SCC(G_T, f);
}

int main(void) {

    // BFS
    cout << "##BFS##" << endl;
    int myVNum_BFS = 10;
    vector<vector<int>> myEdges_BFS{
        {0,1}, {0,2}, {0,3}, {1,4}, {1,5}, {2,5}, {2,6}, {3,4}, {3,6}, {5,7}, {5,8}, {6,7}, {7,8},
        {1,0}, {2,0}, {3,0}, {4,1}, {5,1}, {5,1}, {6,2}, {4,3}, {6,3}, {7,5}, {8,5}, {7,6}, {8,7}
    };
    di_graph BFS(myVNum_BFS, myEdges_BFS);
    BFS.bfs(0);
    cout << endl;

    // DFS
    cout << "##DFS##" << endl;
    int myVnum_DFS = 6;
    vector<vector<int>> myEdges_DFS{
        {0,1}, {0,3}, {1,4}, {2,4}, {2,5}, {3,1}, {4,3}, {5,5}
    };
    di_graph DFS(myVnum_DFS, myEdges_DFS);
    DFS.dfs(DFS.edges);
    cout << endl;


    // topological sort
    cout << "##Topological sort##" << endl;
    int myVnum_TS = 9;
    vector<vector<int>> myEdges_TS{
        {0,1}, {0,3}, {1,2}, {3,2}, {5,6}, {5,7}, {6,3}, {6,7}, {8,7}
    };
    di_graph TS(myVnum_TS, myEdges_TS);
    TS.topological_sort();
    cout << endl;


    // SCC
    cout << "##SCC##" << endl;
    int myVnum_SCC = 8;
    vector<vector<int>> myEdges_SCC{
        {0,1}, {1,2}, {1,4}, {1,5}, {2,6}, {2,3}, {3,2}, {3,7}, {4,0}, {4,5}, {5,6}, {6,5}, {6,7}, {7,7}
    };
    di_graph SCC(myVnum_SCC, myEdges_SCC);
    SCC.find_SCC();
    cout << endl;


    return 0;
}