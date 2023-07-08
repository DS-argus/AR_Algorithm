class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;

        unordered_map<string, vector<string>> store;
        string key;
        for(auto i: strs){
            key = i;
            sort(key.begin(), key.end());

            if(store.count(key)==0){
                store[key] = vector{i};
            }else{
                store[key].push_back(i);
            }
        }

        for (auto i: store){
            result.push_back(i.second);
        }

        return result;
    
        }
};