class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pqueue(begin(stones), end(stones));

        while (pqueue.size()>1){
            int y = pqueue.top(); pqueue.pop();
            int x = pqueue.top(); pqueue.pop();
            if(x!=y) pqueue.push(y-x);
        }
        
        return pqueue.empty()? 0 : pqueue.top();
        
    }
};