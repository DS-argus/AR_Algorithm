#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



int main(){
    // // getDivisions example
    char *s = "abc";
    char **path = NULL;
    int pathSize = 0;

    char ***results = NULL;
    int *resultsSizes = NULL;
    int resultsCount = 0;

    getDivisions(s, 0, path, pathSize, &results, &resultsSizes, &resultsCount);

    for (int i = 0; i < resultsCount; i++) {
        for (int j = 0; j < resultsSizes[i]; j++) {
            printf("%s ", results[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    free2DStringArray(results, resultsSizes, resultsCount);

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
    char s[] = "hello";
    sortString(s);
    printf("%s\n", s); // ehllo



    return 0;
}