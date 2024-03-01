#include <iostream>
#include <list>
#include <vector>
#include <set>

using namespace std;

const int N_VERTEX = 9;

// MST: PRIM (adjacency list, min-priority queue)
// KRUSKAL: 구현 안함 귀찮아

class Heap{
        // first = vertex, second = key
        pair<int, int> *harr;
        int capacity;
        int heap_size;
    public:
        Heap(int capacity): capacity(capacity), heap_size(0) {
            harr = new pair<int, int>[capacity];
        };

        void insertKey(int v, int key){
            if (heap_size == capacity) {
                cout << "\nOverflow: Could not insertKey\n";
                return;
            }
            heap_size++;
            int i = heap_size - 1;
            harr[i] = make_pair(v, key);
        }

        int parent(int i) { return (i-1)/2;}
        int left(int i) {return (2*i+1);}
        int right(int i) {return (2*i+2);}

        void buildMinHeap() {
            int i = parent(heap_size-1);
            for(; i>=0; i--) {
                MinHeapify(i);
            }
        }

        void MinHeapify(int i){
            // Go Down
            int l = left(i);
            int r = right(i);
            int smallest_index = i;
            if (l < heap_size && harr[l].second < harr[smallest_index].second) {
                smallest_index = l;
            }
            if (r < heap_size && harr[r].second < harr[smallest_index].second) {
                smallest_index = r;
            }
            if (smallest_index != i) {
                pair<int, int> tmp = harr[i];
                harr[i] = harr[smallest_index];
                harr[smallest_index] = tmp;
                MinHeapify(smallest_index);
            }
        }

        void printHeap() {
            for(int i = 0; i < heap_size; i++){
                cout << "(" << harr[i].first << ", " << harr[i].second << ") ";
            }
        }

        void heapSort() {
            // 그냥 heap에서 시작해도 됨
            buildMinHeap();
            pair<int,int> tmp;
            int n = heap_size-1;
            for (; n > 0; n--) {
                tmp = harr[0];
                harr[0] = harr[n];
                heap_size--;
                MinHeapify(0);
                cout << "(" << tmp.first << ", " << tmp.second << ") ";
            }
            cout << "(" << harr[0].first << ", " << harr[0].second << ") " << endl;
        }


        pair<int, int> minHeapMinimum() {
            // 이미 min heap이어야 함
            if (heap_size < 1) {
                cout << "heap underflow";
                return make_pair(-1, 0);
            }
            return harr[0];
        }


        pair<int, int> minHeapExtractMin() {
            pair<int, int> min = minHeapMinimum();
            harr[0] = harr[heap_size-1];
            heap_size--;
            MinHeapify(0);
            return min;
        }


        void minHeapDecreaseKey(int v, int key) {
            // 이미 min heap이어야 함

            int index = find_index(v);
            if (index < 0) return;

            if (key > harr[index].second) {
                cout << "new key is larger than current key " << endl;
                return;
            }
            harr[index].second = key;
            int i = index;
            pair<int, int> tmp;
            while(i > 0 && harr[i].second < harr[parent(i)].second) {
                tmp = harr[parent(i)];
                harr[parent(i)] = harr[i];
                harr[i] = tmp;
                i = parent(i);
            }
        }


        void minHeapInsert(int v, int k){
            // 이미 min heap이어야 함

            if (heap_size == capacity) {
                cout << "heap overflow";
                return;
            }
            heap_size++;

            // version 1
            // harr[heap_size-1] = 100000000000000;
            // maxHeapDecreaseKey(heap_size-1, k);

            // version 2
            int i = heap_size - 1;
            harr[i] = make_pair(v, k);
            while (i != 0 && harr[parent(i)].second > harr[i].second) {
                pair<int, int> tmp = harr[parent(i)];
                harr[parent(i)] = harr[i];
                harr[i] = tmp;
                i = parent(i);
            }
        }

        bool empty() {
            return (heap_size == 0);
        }

        bool contain(int v) {
            int i = 0;
            while(i < heap_size){
                if (harr[i].first == v) {
                    return true;
                }
                i++;
            }
            return false;
        }

        int find_index(int v) {
            int index = 0;
            while(index < heap_size){
                if (harr[index].first == v) {
                    return index;
                }
                index++;
            }

            return -1;
        }
};

class undi_weighted_graph {
    public:
        int n_vertex;
        vector< vector<int> > edges;
        int weights[N_VERTEX][N_VERTEX];
        undi_weighted_graph(const int& aN_vertex, const vector<vector<int>>& aEdges, int aWeights[N_VERTEX][N_VERTEX]):
            n_vertex(aN_vertex), edges(aN_vertex, vector<int>(0))
        {
            for(const vector<int>& e: aEdges){
                edges[e[0]].push_back(e[1]);
                edges[e[1]].push_back(e[0]);
            }
            for (int i = 0; i < n_vertex; i++) {
                for (int j = 0; j < n_vertex; j++) {
                    weights[i][j] = aWeights[i][j];
                }
            }
        }
        void MST_prim(const vector<vector<int>>& G, const int w[N_VERTEX][N_VERTEX], int r) {

            int key[n_vertex];
            int p[n_vertex];
            for(int i = 0; i < n_vertex; i++){
                key[i] = 10000;
                p[i] = -1;
            }
            key[r] = 0;
            Heap q(n_vertex);
            for(int i = 0; i < n_vertex; i++){
                q.minHeapInsert(i, key[i]);
            }
            int u;
            while(!q.empty()){
                pair<int, int> min = q.minHeapExtractMin();
                int u = min.first;
                cout << "added edge = (" << p[u] << ", " << u << ") weight = " << min.second << endl;
                for (const int& v: edges[u]){
                    if (q.contain(v) && w[u][v] < key[v]) {
                        p[v] = u;
                        key[v] = w[u][v];
                        q.minHeapDecreaseKey(v, w[u][v]);
                    }
                }
            }
        }

        static bool cmpWeight(tuple<int, int, int>& e1, tuple<int, int, int>& e2) {
            return get<2>(e1) < get<2>(e2);
        }

        int findParent(const int p[], int v) {
            if(p[v] == v) return v;
            return findParent(p, p[v]);
        }

        void uni(int p[], int u, int v){
            int p_u = findParent(p, u);
            int p_v = findParent(p, v);
            if(p_u<p_v) p[p_v] = p_u;
            else p[p_u] = p_v;
        }

        bool isCycle(const int p[], int u, int v) {
            int p_u = findParent(p, u);
            int p_v = findParent(p, v);
            if(p_u==p_v) return true;
            else return false;
        }

        void MST_kruskal(const vector<vector<int>>& G, const int w[N_VERTEX][N_VERTEX]) {
            vector<tuple<int, int, int>> MST(0);

            int parent[n_vertex];

            set<int> S[n_vertex];
            for (int i = 0; i < n_vertex; i++) {
                S[i].insert(i);
                parent[i] = i;
            }
            vector<tuple<int, int, int>> edges_with_weight(0);
            for (int i = 0; i < n_vertex; i++) {
                int n_adj = edges[i].size();
                for (int k = 0; k < n_adj; k++) {
                    int j = edges[i][k];
                    edges_with_weight.push_back(make_tuple(i, j, w[i][j]));
                }
            }
            sort(edges_with_weight.begin(), edges_with_weight.end(), cmpWeight);

            int n_edge = edges_with_weight.size();
            int u, v;
            for (const tuple<int,int,int>& e: edges_with_weight) {
                u = get<0>(e);
                v = get<1>(e);
                if(!isCycle(parent, u, v)){
                    MST.push_back(e);
                    uni(parent, u, v);
                }
            }
            int n_T = MST.size();
            for (int i = 0; i < n_T; i++) {
                cout << "added edge = (" << get<0>(MST[i]) << ", " << get<1>(MST[i]) << ") weight = " << get<2>(MST[i]) << endl;
            }
        }
};

int main(void) {
    // Graph construction using 10 vertices
    int myVNum = N_VERTEX;
    vector<vector<int>> myEdges{
        {0,1}, {0,7}, {1,2}, {1,7}, {2,3}, {2,5}, {2,8}, {3,4}, {3,5}, {4,5}, {5,6}, {6,7}, {6,8}, {7,8}
    };
    int myWeights[N_VERTEX][N_VERTEX] = {
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,14,10,0,2,0,0},
        {0,0,0,0,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };
    undi_weighted_graph myGraph(myVNum, myEdges, myWeights);


    cout << "## Prim's Algorithm ##" << endl;
    myGraph.MST_prim(myGraph.edges, myGraph.weights, 0);
    cout << endl;

    cout << "## Kruskal's Algorithm ##" << endl;
    myGraph.MST_kruskal(myGraph.edges, myGraph.weights);


    return 0;
}