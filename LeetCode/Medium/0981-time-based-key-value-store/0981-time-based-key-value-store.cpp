class TimeMap {
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        if(Tmap.count(key) != 0){
            Tmap[key].push_back(timestamp);
            Vmap[key].push_back(value);
        }else{
            Tmap[key] = vector{timestamp};
            Vmap[key] = vector{value};
        }
    }
    
    string get(string key, int timestamp) {
        if(Tmap.count(key)==0) return "";

        int k = ModifiedBinarySearch(Tmap[key], timestamp);

        if(k!=-1){
            return Vmap[key][k];
        }else{
            return "";
        }
    }

private:
    unordered_map<string,vector<int>> Tmap;
    unordered_map<string,vector<string>> Vmap;
    int ModifiedBinarySearch(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int mid;

        while(start != end + 1){
            mid = (start + end) / 2;

            if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        if(start < nums.size() && nums[start]==target){
            return start;
        }else if(start != 0){
            return start-1;
        }else{
            return -1;
        }

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */