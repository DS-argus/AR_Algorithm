#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// compiler
// gcc utils.c -o utils
// g++ utils.c -o utils

// bool hasCycle(struct ListNode *head) {
//     if (!head) return 0;
//     struct ListNode* slow = head;
//     struct ListNode* fast = head->next;
    
//     while (fast && fast->next) {
//         if (fast == slow) return 1;
//         fast = fast->next->next;
//         slow = slow->next;
//     }
//     return 0;
// }

// isPalindrome using DP
// input char* s
// output int** DP table
int **isPalindrome_DP(char *s) {
    int len = strlen(s);
    int **dp = (int **)malloc(sizeof(int *)*len);
    for (int i = 0; i < len; i++) {
        dp[i] = (int *)malloc(sizeof(int)*len);
        for (int j = 0; j < len; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        } else {
            dp[i][i + 1] = 0;
        }
    }
    for (int l = 3; l <= len; l++) {
        for (int i = 0; i <= len - l; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return dp;
}

// isPalindrome using DP
int isPalindrome(char *s, int start, int end, int **dp) {
    if (start >= end) {
        return 1;
    }
    if (dp[start][end] != -1) {
        return dp[start][end];
    }
    if (s[start] != s[end]) {
        return dp[start][end] = 0;
    }
    return dp[start][end] = isPalindrome(s, start + 1, end - 1, dp);
}

int isPalindrome_str(char *str, int start, int end) {
    // 주어진 문자열에서 start, end까지가 palindrome인가?
    // Example
    //      isPalindrome(s, 0, strlen(s)-1) : s 전체가 palindrome인가?
    while (start < end) {
        if (str[start++] != str[end--]) return 0;
    }
    return 1;
}

int isPalindrome_int(int n) {
    int reverse = 0, temp = n;

    while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return n == reverse;
}

int binarysearch(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    
    while (left <= right){
        int middle = left + (right - left) / 2;
        
        if (nums[middle] == target)
            return middle;
        
        else if (nums[middle] < target)
            left = middle + 1;
        
        else
            right = middle - 1;
    }
    return -1;
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // Create temp arrays 
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 
  
    // Initial index of second subarray 
    j = 0; 
  
    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

// substring인지 체크하는 함수
int isSubstring(char *s, char *t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    if (s_len < t_len) {
        return 0;
    }
    for (int i = 0; i <= s_len - t_len; i++) {
        int flag = 1;
        for (int j = 0; j < t_len; j++) {
            if (s[i + j] != t[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return 1;
        }
    }
    return 0;
}

// int array sorting해주는 함수: quick sort 사용   
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

// insertion sort 사용해서 int array sorting해주는 함수
void insertionSort(int* nums, int numsSize){
    for (int i = 1; i < numsSize; i++) {
        int j = i - 1;
        int key = nums[i];
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

// int array를 동적할당 해서 만들고 0으로 초기화하는 함수
int* createIntArray(int size) {
    int *arr = (int *)malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
    return arr;
}

//int array에서 특정 int를 제거해주는, void 함수
void removeElement_int(int* nums, int *numsSize, int val){
    int index = 0;
    for (int i = 0; i < *numsSize; i++) {
        if (nums[i] != val) {
            nums[index++] = nums[i];
        }
    }
    *numsSize = index;
}

// int array를 받으면 중복된 값을 제거해서 하나만 return 하는 함수
// sorting 알고리즘 사용하지 말고
int removeDuplicates_int2(int* nums, int numsSize){
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            nums[index++] = nums[i];
        }
    }
    return index;
}

// int를 문자로 바꾸는 함수
char* intToChar(int n){
    char *str = (char *)malloc(12);
    sprintf(str, "%d", n);
    return str;
}

// 문자를 int로 바꾸는 함수
int charToInt(char *str){
    int n;
    sscanf(str, "%d", &n);
    return n;
}

//문자를 longlong으로 바꾸는 함수
long long charToLongLong(char *str){
    long long n;
    sscanf(str, "%lld", &n);
    return n;
}

// 문자열에서 중복제거하는 함수
void removeDuplicates(char *str) {
    int len = strlen(str);
    int index = 0;
    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (i == j) {
            str[index++] = str[i];
        }
    }
    str[index] = '\0';
}

// 문자열에서 중복을 제거한 새로운 문자를 return
char* removeDuplicates_str(char *str) {
    int len = strlen(str);
    char *new_str = (char *)malloc(len + 1);
    int index = 0;
    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (i == j) {
            new_str[index++] = str[i];
        }
    }
    new_str[index] = '\0';
    return new_str;
}

// 문자열 sorting하는 함수 : insertion sort 사용
void sortString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// 이 숫자가 int 배열에 있는지 확인하는 함수
int isIntInArray(int *arr, int size, int n) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            return 1;
        }
    }
    return 0;
}

// 이 문자가 문자열에 있는지 확인하는 함수
int isCharInString(char *str, char ch) {
    while (*str) {
        if (*str == ch) {
            return 1;
        }
        str++;
    }
    return 0;
}

//anagram인지 확인하는 함수
int isAnagram(char *s, char *t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    if (s_len != t_len) {
        return 0;
    }
    int s_count[26] = {0};
    int t_count[26] = {0};
    for (int i = 0; i < s_len; i++) {
        s_count[s[i] - 'a']++;
        t_count[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (s_count[i] != t_count[i]) {
            return 0;
        }
    }
    return 1;
}

//문자열 뒤집는 함수
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// 문자열 길이 구하는 함수
int str_len(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// C function으로 slicing을 구현
// 파이썬과 동일하게 동작하는 듯.
char *slice(const char *str, int start, int end) {
    int len = end - start;
    char *slice = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        slice[i] = str[start + i];
    }
    slice[len] = '\0';
    return slice;
}

// 문자열에서 특정 index의 문자를 제거하는 함수
void removeChar(char *str, int index) {
    int len = strlen(str);
    for (int i = index; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = '\0';
}

// 문자열에서 특정 index의 문자를 제거한 새로운 문자열 return하는 함수
char *removeChar_str(const char *str, int index) {
    int len = strlen(str);
    char *new_str = (char *)malloc(len);
    for (int i = 0; i < len - 1; i++) {
        if (i < index) {
            new_str[i] = str[i];
        } else {
            new_str[i] = str[i + 1];
        }
    }
    new_str[len - 1] = '\0';
    return new_str;
}


// C function 으로 문자열에서 특정 문자를 제거하는 함수
void eliminate(char *str, char ch) {
    int i, j;
    for (i = j = 0; str[i] != '\0'; i++) {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// C function 으로 문자열에서 특정 문자를 제거하는 함수, 첫번째 문자만 제거
void eliminate_first(char *str, char ch) {
    int i, j;
    int found = 0; // 추가된 변수, ch를 찾았는지 여부를 추적합니다.
    for (i = j = 0; str[i] != '\0'; i++) {
        if (str[i] == ch && !found) {
            found = 1; // ch를 찾았으므로, found를 1로 설정합니다.
            continue; // 이번 루프를 건너뛰고, ch를 제외합니다.
        }
        str[j++] = str[i]; // 그 외의 경우, 문자를 복사합니다.
    }
    str[j] = '\0'; // 문자열의 끝을 표시합니다.
}

// Function to clone a string
char *cloneString(const char *str) {
    char *clone = (char *)malloc(strlen(str) + 1);
    strcpy(clone, str);
    return clone;
}

// Function to append a string to an array of strings
void appendStringToArray(char ***array, int *size, const char *str) {
    (*size)++;  // size를 1 증가시킴
    *array = (char **)realloc(*array, (*size) * sizeof(char *));    // size만큼의 메모리 할당
    (*array)[(*size) - 1] = cloneString(str);   // 마지막에 str을 추가
}

// Function to free memory allocated for an array of strings
void freeStringArray(char **array, int size) {
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

// Recursive function to generate all substrings
void getSubstrings(const char *s, int start, char ***results, int *size, int k) {
    int len = strlen(s);
    if (len == k) {
        appendStringToArray(results, size, s);
        return;
    }

    for (int end = start; end < len; end++) {
        char *substring = (char *)malloc(len); // len instead of len + 1 because we're removing a char
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (i != end) {
                substring[j++] = s[i];
            }
        }
        substring[j] = '\0'; // Null-terminate the new string
        getSubstrings(substring, end, results, size, k);
        free(substring);
    }
}

// Function to free a 2D array of strings
void free2DStringArray(char ***array, int *sizes, int count) {
    for (int i = 0; i < count; i++) {
        freeStringArray(array[i], sizes[i]);
    }
    free(array);
    free(sizes);
}

// Recursive function to get all divisions
void getDivisions(const char *s, int start, char **path, int pathSize, char ****results, int **resultsSizes, int *resultsCount) {
    int len = strlen(s);
    if (start == len) {
        // Clone path and add to results
        (*resultsCount)++;
        *results = realloc(*results, (*resultsCount) * sizeof(char **));
        (*resultsSizes) = realloc(*resultsSizes, (*resultsCount) * sizeof(int));
        (*results)[*resultsCount - 1] = malloc(pathSize * sizeof(char *));
        (*resultsSizes)[*resultsCount - 1] = pathSize;
        for (int i = 0; i < pathSize; i++) {
            (*results)[*resultsCount - 1][i] = cloneString(path[i]);
        }
        return;
    }

    for (int end = start + 1; end <= len; end++) {
        
        // Create a new segment of the string
        char *segment = cloneString(s + start); // string의 뒷부분 복사
        segment[end - start] = '\0'; // Properly terminate the new segment

        // Append segment to path and call recursively
        char **newPath = malloc((pathSize + 1) * sizeof(char *));   // pathSize + 1만큼의 메모리 할당
        for (int i = 0; i < pathSize; i++) {
            newPath[i] = path[i]; // Copy existing path
        }
        newPath[pathSize] = segment; // Add new segment

        getDivisions(s, end, newPath, pathSize + 1, results, resultsSizes, resultsCount);

        // Free the allocated memory for newPath except the last element
        free(segment);
        free(newPath);
    }
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    // char** str : ["eat", "tea", "tan", "ate", "nat", "bat"] 같은 문자열을 담은 배열
    // int strsSize : 주어지는 문자열을 담은 배열의 길이
    // int* returnSize : 결과로 반환되는 배열의 길이 -> 계속 증가시키고 할당하고 해야함
    // int** returnColumnSizes : 결과로 반환되는 배열의 각 요소의 길이를 담은 배열, list안의 list의 길이를 담은 배열

    char ***result = (char ***)malloc(sizeof(char **)*strsSize); // Allocate memory for the maximum possible number of groups
    int *resultSizes = (int *)malloc(sizeof(int)*strsSize); // Allocate memory for the sizes of each group
    int resultCount = 0;

    for (int i = 0; i < strsSize; i++) {
        int found = 0;
        for (int j = 0; j < resultCount; j++) {
            if (isAnagram(strs[i], result[j][0])) {
                appendStringToArray(&result[j], &resultSizes[j], strs[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            // Allocate memory for a new group
            result[resultCount] = NULL; // Initialize the new group
            resultSizes[resultCount] = 0; // Initialize the size of the new group
            appendStringToArray(&result[resultCount], &resultSizes[resultCount], strs[i]);
            resultCount++;
        }
    }

    *returnSize = resultCount;
    *returnColumnSizes = resultSizes;
    return result;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);

}

void permuteHelper(int *nums, int numsSize, int pathSize, int *path, int *visited, int **result, int *resultCount, int *resultSizes) {
    if (pathSize == numsSize) {
        result[*resultCount] = (int *)malloc(sizeof(int)*numsSize);
        resultSizes[*resultCount] = numsSize;
        for (int i = 0; i < numsSize; i++) {
            result[*resultCount][i] = path[i];
        }
        (*resultCount)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            path[pathSize] = nums[i];
            permuteHelper(nums, numsSize, pathSize + 1, path, visited, result, resultCount, resultSizes);
            visited[i] = 0;
        }
    }
}

//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **result = (int **)malloc(sizeof(int *)*factorial(numsSize));
    int *resultSizes = (int *)malloc(sizeof(int)*factorial(numsSize));
    int resultCount = 0;
    int *path = (int *)malloc(sizeof(int)*numsSize);
    int *visited = (int *)malloc(sizeof(int)*numsSize);
    for (int i = 0; i < numsSize; i++) {
        visited[i] = 0;
    }
    permuteHelper(nums, numsSize, 0, path, visited, result, &resultCount, resultSizes);
    *returnSize = resultCount;
    *returnColumnSizes = resultSizes;
    free(visited);
    free(path);
    return result;
}

// NxN 2D int array를 모두 출력하는 함수
void print2DIntArray(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

//Given a string `s`, return the minimum number of characters that need to be deleted to obtain the longest palindromic subsequence and print the resulting subsequence itself.
//input char *s, output int and print the longest palindromic subsequence
int minDeletionsToObtainPalindrome(char *s) {
    int len = strlen(s);
    int **dp = (int **)malloc(sizeof(int *)*len);
    for (int i = 0; i < len; i++) {
        dp[i] = (int *)malloc(sizeof(int)*len);
        for (int j = 0; j < len; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 2;
        } else {
            dp[i][i + 1] = 1;
        }
    }
    
    for (int l = 3; l <= len; l++) {
        for (int i = 0; i <= len - l; i++) {
            int j = i + l - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = dp[i + 1][j] > dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1];
            }
        }
    }
    int result = len - dp[0][len - 1];
    for (int i = 0; i < len; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}


int main(){
    // // getDivisions example
    // char *s = "abc";
    // char **path = NULL;
    // int pathSize = 0;

    // char ***results = NULL;
    // int *resultsSizes = NULL;
    // int resultsCount = 0;

    // getDivisions(s, 0, path, pathSize, &results, &resultsSizes, &resultsCount);

    // for (int i = 0; i < resultsCount; i++) {
    //     for (int j = 0; j < resultsSizes[i]; j++) {
    //         printf("%s ", results[i][j]);
    //     }
    //     printf("\n");
    // }

    // // Free allocated memory
    // free2DStringArray(results, resultsSizes, resultsCount);

    // getSubstrings example
    // const char *s = "abcde";
    // int k = 3;

    // char **substrings = NULL;
    // int substringsLen = 0;

    // getSubstrings(s, 0, &substrings, &substringsLen, k);
    // printf("%d\n", substringsLen);
    // // Print the results
    // for (int i = 0; i < substringsLen; i++) {
    //     printf("%s\n", substrings[i]);
    // }

    // // Free allocated memory
    // freeStringArray(substrings, substringsLen);


    // eliminate, eliminate_first example
    // char str[] = "Hello, World!";
    // eliminate_first(str, 'H');
    // printf("%s\n", str); // Heo, Word!

    // slicing example
    // char *s = "Hello, World!";
    // char *sliced = slice(s, 2, 13);
    // printf("%s\n", sliced); // Hello
    // free(sliced);

    // str_len example
    // char *s = "Hello, World!";
    // printf("%d\n", str_len(s)); // 13

    // reverse example
    // char s[] = "Hello, World!";
    // reverse(s);
    // printf("%s\n", s); // !dlroW ,olleH

    // isAnagram example
    // char *s = "anagram";
    // char *t = "nagaram";
    // printf("%d\n", isAnagram(s, t)); // 1

    // sortString example
    // char s[] = "hello";
    // sortString(s);
    // printf("%s\n", s); // ehllo

    // removeDuplicates example
    // char s[] = "hello";
    // removeDuplicates(s);
    // printf("%s\n", s); // helo

    // more complicated example for removeDuplicates
    // char s[] = "hello, world!";
    // removeDuplicates(s);
    // printf("%s\n", s); // helo, wrd!
    
    // removeDuplicates_int example
    // int nums[] = {1, 1, 2};
    // int returnSize;
    // int *result = removeDuplicates_int(nums, 3, &returnSize);
    // for (int i = 0; i < returnSize; i++) {
    //     printf("%d ", result[i]);
    // }
    // printf("\n");
    // free(result);

    // // removeElement_int example
    // int nums[] = {3, 2, 2, 3};
    // int numsSize = 4;
    // int val = 3;
    // printf("%d\n", numsSize); // 4
    // removeElement_int(nums, &numsSize, val);
    // for (int i = 0; i < numsSize; i++) {
    //     printf("%d ", nums[i]);
    // }
    // printf("\n");
    // printf("%d\n", numsSize);   // 2

    // removeDuplicates_int2 example
    // int nums[] = {1, 1, 2};
    // int returnSize = removeDuplicates_int2(nums, 3);
    // for (int i = 0; i < returnSize; i++) {
    //     printf("%d ", nums[i]);
    // }
    // printf("\n");

    // isPalindrome DP example
    // char *s = "abbaadfage";
    // int len = strlen(s);
    // int **dp = (int **)malloc(sizeof(int *)*len);
    // for (int i = 0; i < len; i++) {
    //     dp[i] = (int *)malloc(sizeof(int)*len);
    //     for (int j = 0; j < len; j++) {
    //         dp[i][j] = -1;
    //     }
    // }
    // printf("%d\n", isPalindrome(s, 0, len - 1, dp)); // 1


    // intToChar example
    // int n = 123;
    // char *str = intToChar(n);
    // printf("%s\n", str); // 123
    // free(str);

    // charToInt example
    // char *str = "123";
    // int n = charToInt(str);
    // printf("%d\n", n); // 123

    //quickSort example
    // int nums[] = {3, 2, 1, 5, 6, 4};
    // quickSort(nums, 6);
    // for (int i = 0; i < 6; i++) {
    //     printf("%d ", nums[i]);
    // }
    // printf("\n");

    //isPalindrome_DP example
    // char *s = "abba";
    // int **dp = isPalindrome_DP(s);
    // print2DIntArray(dp, 4);

    // slice example
    // char *s = "casdfasda";
    // char *sliced = slice(s, 0, 4);
    // printf("%s\n", sliced);
    // free(sliced);

    // minDeletionsToObtainPalindrome example
    char *s = "unique";
    printf("%d\n", minDeletionsToObtainPalindrome(s)); // 1


    return 0;
}