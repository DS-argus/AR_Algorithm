#include <iostream>
#include <vector>


#define INF 99999
#define MININF -99999

using namespace std;

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}


class minHeap{
private:
    pair<int, int>* harr;
    int capacity;
    int heap_size;
public:
    int parent(int i) {return (i-1)/2;};
    int left(int i) {return 2*i+1;};
    int right(int i) {return 2*i+2;};

    minHeap(int c) : capacity(c), heap_size(0) {
        harr = new pair<int, int>[c];
    };

    void insertKey(int x, int key) {
        if(heap_size == capacity) {
            cout << "error : full of capacity.";
        }
        heap_size++;
        harr[heap_size-1] = make_pair(x, key);
        while (x != 0 && harr[parent(x)].second > harr[x].second) {
            swap(harr[parent(x)], harr[x]);
            x = parent(x);
        }
    }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && harr[smallest].second > harr[l].second) {
            smallest = l;
        }
        if (r < heap_size && harr[smallest].second > harr[r].second) {
            smallest = r;
        }
        else{
            smallest = i;
        }
        if(smallest != i) {
            swap(harr[i], harr[smallest]);
            minHeapify(smallest);
        }
    }

   pair<int, int> extractMin() {
        pair<int, int> min = harr[0];
        harr[0] = harr[heap_size];
        heap_size--;
        minHeapify(0);
        return min;
    }

    void decreaseKey(int v, int weight, int V) {
        int index = -1;

        for (int i = 0; i < V; i++) {
            if (harr[i].first == v) {
                index = i;
            }
        }
        if (index == -1) return;
        if(weight >= harr[index].second) {
            cout << "new key is greater than old key." << endl;
        }
        else{
            harr[index].second = weight; // vertex search
            while(harr[index].first < heap_size && harr[parent(index)].second > harr[index].second) {
                swap(harr[parent(index)], harr[index]);
                index = parent(index);
            }
        }
    }

    bool empty() {
        if(heap_size == 0) {
            return true;
        }
        else{
            return false;
        }
    }

};

class Graph
{
    private:
        int V;    // No. of vertices'
        vector<pair<int, int>> *adj;
    public:
        Graph(int V);   // Constructor
        void addEdge(int u, int v, int weight);
        void DijkstraSSSP();
        bool Bellman_Ford();

};

Graph::Graph(int V) :V(V)
{
    adj = new vector<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}


bool Graph::Bellman_Ford() {

    int d[V];
    int p[V];
    for (int i = 0; i < V; i++){
        d[i] = INF;
        p[i] = -1;
    }
    int root = 0;
    d[root] = 0;
    int v;
    vector<pair<int, int>>::iterator it;
    // for i = 1 to |G.V| - 1
    for(int i = 0; i < V-1; i++){
        // for each edge
        for(int u = 0; u < V; u++){
            for(it = adj[u].begin(); it != adj[u].end(); it++){
                // relax
                v = (*it).first;
                if(d[v] > d[u] + (*it).second){
                    d[v] = d[u] + (*it).second;
                    p[v] = u;
                }
            }
        }
    }
    // one more update
    for(int u = 0; u < V; u++){
        for(it = adj[u].begin(); it != adj[u].end(); it++){
            v = (*it).first;
            if(d[v] > d[u] + (*it).second){
                return false;
            }
        }
    }
    for (int i = 0; i < V; i++){
        cout << "vertex: " << i << ", d: " << d[i] << ", p: " << p[i] << endl;
    }
    return true;
}

void Graph::DijkstraSSSP() {
    minHeap Q(V);
    for(int i = 0; i < V; i++) {
        Q.insertKey(i, INF);
    }
    int root = 0;

    vector<int> key(V, INF);
    pair<int, int> *S;
    key[root] = 0;
    Q.decreaseKey(root, 0, V);

    int u;
    pair<int, int> min;
    while(!Q.empty()){
        min = Q.extractMin();
        u = min.first;
        vector<pair<int, int>>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++){
            int v = (*i).first;
            int weight = (*i).second;
            if(key[v] > key[u] + weight){
                key[v] = key[u] + weight;
                Q.decreaseKey(v, key[v], V);
            }
        }
    }


    for (int i = 0; i < V; i++){
        cout << "vertex: " << i << ", d: " << key[i] << endl;
    }
}


int main()
{
    // Create a graph given in the above diagram.
    // Here vertex numbers are 0, 1, 2, 3, 4, 5 with
    // following mappings: 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 11);
    g.addEdge(4, 5, 12);

    int s = 0;
    cout << "Following are shortest distances from source " << s << endl;
    g.DijkstraSSSP();
    g.Bellman_Ford();
    return 0;
}
