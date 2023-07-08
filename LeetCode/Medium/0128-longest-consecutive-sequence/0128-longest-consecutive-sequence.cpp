class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // if (num.size()<=1) return num.size();

        // set<int> sortedSet;
        // for(auto i: num) sortedSet.insert(i); 

        // set<int>::iterator l = sortedSet.begin();
        // set<int>::iterator r = next(l);
        // int max = 0;

        // while(r!=sortedSet.end()){
        //     if (*r - *l == distance(l, r)){
        //         r = next(r, 1);
        //     }else{
        //         if (distance(l, r) > max) max = distance(l, r);
        //         l = r;
        //         r = next(l);
        //     }
        // }

        // if (distance(l, r) > max) max = distance(l, r);

        // return max;

        if (num.size()<=1) return num.size();

        // vector 중복 제거하고 크기 오름차순 정렬 위해 map 사용
        set<int> sortedSet;
        for(auto& i: num) sortedSet.insert(i);
        
        num.clear();

        for(set<int>::iterator it = sortedSet.begin(); it != sortedSet.end(); it++) num.push_back(*it);
        
        int max = 0;
        int l = 0;
        int r = 1;

        while (r < num.size()){
            if (num[r]-num[l] == r-l){
                r++;
            }else{
                if (r-l > max) max = r-l;
                l = r;
                r = l+1;
            }
        }

        // 모든 원소가 연속이라 한번도 max 업데이트 안된 경우
        if (r-l > max) max = r-l;

        return max;
    }
};