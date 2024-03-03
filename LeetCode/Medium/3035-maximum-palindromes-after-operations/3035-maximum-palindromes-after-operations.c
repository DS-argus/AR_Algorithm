void quickSort(int* nums, int numsSize){
    if (numsSize <= 1) return;
    int pivot = nums[numsSize / 2];
    int i, j;
    for (i = 0, j = numsSize - 1; ; i++, j--) {
        while (nums[i] < pivot) i++;
        while (nums[j] > pivot) j--;
        if (i >= j) break;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    quickSort(nums, i);
    quickSort(nums + i, numsSize - i);
}

int maxPalindromesAfterOperations(char **words, int wordsSize) {
    int cnt[26] = {0}, pairs = 0, oddCounts = 0, evenWords = 0, oddWords = 0;
    int* needPair = (int*)malloc(sizeof(int)*wordsSize);
    int* sizes = (int*)malloc(sizeof(int)*wordsSize);
    int total_needPair = 0;
    for (int i = 0; i < wordsSize; ++i) {
        
        int wordLen = strlen(words[i]);
        sizes[i] = wordLen;
        if (wordLen % 2 == 0) {
            evenWords++;
        } else {
            oddWords++;
        }

        needPair[i] = wordLen / 2;
        total_needPair += wordLen / 2;
        
        for (int j = 0; j < wordLen; ++j) {
            pairs += (++cnt[words[i][j] - 'a']) % 2 == 0 ? 1 : 0;
        }
    }
    quickSort(sizes, wordsSize);
    int res = 0;
    for (int i = 0; i < wordsSize; i++){
        int wordLen = sizes[i];
        
        if (pairs - wordLen/2>=0){
            pairs -= wordLen/2;
            res += 1;
        }
    }

    return res;
}