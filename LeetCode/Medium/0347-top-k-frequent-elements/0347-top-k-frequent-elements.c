int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int MIN = 1e4;
    int MAX = -1e4;

    // find min, max from given array
    for(int i = 0; i < numsSize; i ++){
        if (nums[i] < MIN) MIN = nums[i];
        if (nums[i] > MAX) MAX = nums[i];
    }

    // MAX - MIN + 1만큼의 array 할당
    int range = MAX-MIN+1;
    int* counter = (int*)malloc(sizeof(int) * range);
    memset(counter, 0, sizeof(int) * range); // malloc 사용 시 초기화
    
    // index에 해당하는 자리에 개수 counting
    for(int i = 0; i < numsSize; i ++){
        counter[nums[i]-MIN]++;
    }

    int* result = (int*)malloc(sizeof(int) * k);
    *returnSize = k;

    int i = 0;
    int returnsize = 0;
    while (i<k){
        int MAX = -1;
        int idx = -1;
        
        for(int j = 0; j < range; j++){
            if(counter[j] > MAX) {
                MAX = counter[j];
                idx = j;
            }
        }

        result[i] = idx+MIN;
        counter[idx] = 0;
        i++;
    }

    return result;
}

