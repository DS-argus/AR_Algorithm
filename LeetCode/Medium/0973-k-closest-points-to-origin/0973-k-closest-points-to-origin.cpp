class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pqueue;
        for (auto point: points){
            int dist = point[0]*point[0] + point[1]*point[1];
            pqueue.push(make_pair(dist, point));
        }

        vector<vector<int>> result;
        for(int i=0; i<k; i++){
            result.push_back(pqueue.top().second);
            pqueue.pop();
        }

        return result;
        
    }
};