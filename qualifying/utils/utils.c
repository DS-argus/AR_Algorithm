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

void Eliminate(char *str, char ch)
{
    for (; *str != '\0'; str++)//종료 문자를 만날 때까지 반복
    {
        if (*str == ch)//ch와 같은 문자일 때
        {
            strcpy(str, str + 1);
            str--;
        }
    }
}

// Function to clone a string
char *cloneString(const char *str) {
    char *clone = (char *)malloc(strlen(str) + 1);
    strcpy(clone, str);
    return clone;
}

// Function to append a string to an array of strings
void appendStringToArray(char ***array, int *size, const char *str) {
    (*size)++;
    *array = (char **)realloc(*array, (*size) * sizeof(char *));
    (*array)[(*size) - 1] = cloneString(str);
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
        char *segment = cloneString(s + start);
        segment[end - start] = '\0'; // Properly terminate the new segment

        // Append segment to path and call recursively
        char **newPath = malloc((pathSize + 1) * sizeof(char *));
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
    const char *s = "abcde";
    int k = 3;

    char **substrings = NULL;
    int substringsLen = 0;

    getSubstrings(s, 0, &substrings, &substringsLen, k);
    printf("%d\n", substringsLen);
    // Print the results
    for (int i = 0; i < substringsLen; i++) {
        printf("%s\n", substrings[i]);
    }

    // Free allocated memory
    freeStringArray(substrings, substringsLen);

    return 0;

}