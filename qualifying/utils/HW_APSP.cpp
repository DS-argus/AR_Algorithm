#include <iostream>
#include <vector>

#define INF 1000000
#define n_vertex 5

using namespace std;

void swap(int & a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

class Graph
{
    public:
        int V;
        int** adj;
        // int** L;
        // int** P;

        Graph(int V) {
            this->V = V;
            adj = new int*[V];
            // L = new int*[V];
            // P = new int*[V];

            for (int i = 0; i < V; i++){
                adj[i] = new int[V];
                // L[i] = new int[V];
                // P[i]= new int[V];
                for (int j = 0; j < V; j++){
                    if ( i == j ) {
                        adj[i][j] = 0;
                        // L[i][j] = 0;
                    } else {
                        adj[i][j] = INF;
                        // L[i][j] = INF;
                        // P[i][j] = -1;
                    }
                }
            }
        }

        void addEdge(int i, int j, int w) {
            adj[i][j] = w;
        }

        // void print(int i, int j) {
        //     if (i == j) {
        //         cout << i << " ";
        //     } else if (P[i][j] == -1) {
        //         cout << "no path" << endl;
        //     } else {
        //         print(i, P[i][j]);
        //         cout << j << " ";
        //     }
        // }

        void extend_shortest_paths(int L_bef[n_vertex][n_vertex], int W[n_vertex][n_vertex], int L_af[n_vertex][n_vertex]) {
            for (int i = 0; i < V; i++){
                for (int j = 0; j < V; j++){
                    for (int k = 0; k < V; k++) {
                        if (L_af[i][j] > L_bef[i][k] + W[k][j]) {
                            L_af[i][j] = L_bef[i][k] + W[k][j];
                        }
                    }
                }
            }
        }

        void slow_APSP() {
            int W[n_vertex][n_vertex];
            for (int i = 0; i < n_vertex; i++){
                for (int j =0; j < n_vertex; j++){
                    W[i][j] = adj[i][j];
                }
            }
            int L[n_vertex][n_vertex];
            for(int i = 0; i < V; i++){
                for(int j = 0; j < V; j++){
                    if(i == j){
                        L[i][j] = 0;
                    }else{
                        L[i][j] = INF;
                    }
                }
            }
            for (int r = 0; r < n_vertex-1; r++) {
                int M[n_vertex][n_vertex];
                fill(M[0], M[0]+V*V, INF);
                extend_shortest_paths(L, W, M);
                for (int i = 0; i < n_vertex; i++){
                    for (int j =0; j < n_vertex; j++){
                        L[i][j] = M[i][j];
                    }
                }
            }
            cout << "D matrix" << endl;
            for (int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    cout << L[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        void faster_APSP() {
            int L[n_vertex][n_vertex];
            int M[n_vertex][n_vertex];
            for (int i = 0; i < n_vertex; i++){
                for (int j =0; j < n_vertex; j++){
                    L[i][j] = adj[i][j];
                }
            }
            // for while loop
            int r = 1;
            while (r < n_vertex-1) {
                fill(&M[0][0], &M[0][0]+n_vertex*n_vertex, INF);
                extend_shortest_paths(L, L, M);
                for (int i = 0; i < n_vertex; i++){
                    for (int j =0; j < n_vertex; j++){
                        L[i][j] = M[i][j];
                    }
                }
                r *= 2;
            }
            cout << "D mataix" << endl;
            for (int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    cout << L[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        void floyd_warshall(){
            // initialization
            int d[n_vertex][n_vertex];
            int p[n_vertex][n_vertex];

            for (int i = 0; i < n_vertex; i++){
                for (int j = 0; j < n_vertex; j++){
                    d[i][j] = adj[i][j];
                    p[i][j] = -1;
                    if (i != j && adj[i][j] != INF){
                        p[i][j] = i+1;
                    }
                }
            }
            for (int k = 0; k < n_vertex; k++) {
                for (int i = 0; i < n_vertex; i++) {
                    for (int j = 0; j < n_vertex; j++) {
                        if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j]) {
                            d[i][j] = d[i][k] + d[k][j];
                            p[i][j] = p[k][j];
                        }
                    }
                }
                cout << "D matrix" << endl;
                for (int i = 0; i < n_vertex; i++) {
                    for(int j = 0; j < n_vertex; j++) {
                        cout << d[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
                cout << "P matrix" << endl;
                for (int i = 0; i < n_vertex; i++) {
                    for(int j = 0; j < n_vertex; j++) {
                        cout << p[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }

            
        }

};

int main(void) {
    // 강의안 APSP 그래프 참고
    // Graph G(n_vertex);
    // G.addEdge(0, 1, 3);
    // G.addEdge(0, 2, 8);
    // G.addEdge(1, 2, 4);
    // G.addEdge(1, 3, 11);
    // G.addEdge(2, 3, 7);
    // G.addEdge(3, 0, 4);
    // G.slow_APSP();
    // cout << endl;
    // G.faster_APSP();
    // G.floyd_warshall();

    // 강의안 바탕이기 때문에
    // simple APSP에서는 n_vertex = 4
    // floyd warshall에서는 n_vertex = 5
    // 로 맨 위 코드를 고쳐주셔야 합니다.

    // 강의안 floyd warshall 그래프 참고
    Graph fw(n_vertex);
    fw.addEdge(0, 1, 3);
    fw.addEdge(0, 2, 8);
    fw.addEdge(0, 4, -4);
    fw.addEdge(1, 3, 1);
    fw.addEdge(1, 4, 7);
    fw.addEdge(2, 1, 4);
    fw.addEdge(3, 2, -5);
    fw.addEdge(3, 0, 2);
    fw.addEdge(4, 3, 6);

    // fw.addEdge(0,2,5);
    // fw.addEdge(0,3,4);
    // fw.addEdge(1,0,3);
    // fw.addEdge(2,3,2);
    // fw.addEdge(3,1,1);
    // fw.addEdge(3,2,1);
    // fw.addEdge(4,1,4);
    // fw.addEdge(4,3,2);

    fw.floyd_warshall();
    fw.slow_APSP();
    fw.faster_APSP();
}