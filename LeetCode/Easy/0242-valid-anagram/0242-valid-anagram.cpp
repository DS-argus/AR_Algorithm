class Solution {
public:
    bool isAnagram(string s, string t) {
        if  (t.length() != s.length()) return false;

        // store letter of s in unordered_map
        unordered_map<char, int> store;

        for (char c : s){
            if(store.count(c)){
                store[c]++;
            }else{
                store.insert(make_pair(c, 1));
            }
        }

        // check letter of t in the map
        for (auto i: t){
            if (store.count(i) != 0){
                store[i]--;
            }else{
                return false;
            }
        }

        // chech num of each letter is same
        for (auto i: store){
            if(i.second != 0){
                return false;
            }
        }
        return true;
    }
};