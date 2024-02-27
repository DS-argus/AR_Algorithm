#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class GNode {
public:
    string id;
    string color;
    int distance;
    GNode* parent;

    GNode(string id, string color = "W", int distance = 0, GNode* parent = nullptr)
        : id(id), color(color), distance(distance), parent(parent) {}

    // friend ostream& operator<<(ostream& os, const GNode& node) {
    //     os << node.id;
    //     return os;
    // }
};

map<int, vector<string>> bfs(unordered_map<GNode*, vector<GNode*>>& G, GNode* s) {
    map<int, vector<string>> depth_dict;
    queue<GNode*> q;
    vector<string> V_list;

    q.push(s);
    V_list.push_back(s->id);

    while (!q.empty()) {
        GNode* cnt = q.front();
        q.pop();

        depth_dict[cnt->distance].push_back(cnt->id);
        cnt->color = "B";

        for (auto neighbor : G[cnt]) {
            if (neighbor->color == "W" && find(V_list.begin(), V_list.end(), neighbor->id) == V_list.end()) {
                neighbor->distance = cnt->distance + 1;
                q.push(neighbor);
                V_list.push_back(neighbor->id);
            }
        }
    }

    return depth_dict;
}

vector<vector<string>> level_partition(unordered_map<GNode*, vector<GNode*>>& G, GNode* s) {
    map<int, vector<string>> levels = bfs(G, s);
    vector<vector<string>> result;

    for (auto& level : levels) {
        result.push_back(level.second);
    }

    return result;
}

int main() {
    GNode* r = new GNode("r");
    GNode* s = new GNode("s");
    GNode* t = new GNode("t");
    GNode* u = new GNode("u");
    GNode* v = new GNode("v");
    GNode* w = new GNode("w");
    GNode* x = new GNode("x");
    GNode* y = new GNode("y");

    unordered_map<GNode*, vector<GNode*>> G;
    G[r] = {s, v};
    G[s] = {w, r};
    G[t] = {w, x, u};
    G[u] = {t, x, y};
    G[v] = {r};
    G[w] = {s, t, x};
    G[x] = {w, t, u, y};
    G[y] = {x, u};

    vector<vector<string>> partitions = level_partition(G, s);

    for (auto& level : partitions) {
        for (auto& node : level) {
            cout << node << " ";
        }
        cout << endl;
    }

    // Clean up dynamically allocated nodes
    delete r;
    delete s;
    delete t;
    delete u;
    delete v;
    delete w;
    delete x;
    delete y;

    return 0;
}
