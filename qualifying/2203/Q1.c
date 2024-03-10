#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int palindrome(char* s){
    
    for(int i= 0; i < strlen(s)/2+1; i++){
        if (s[i] != s[strlen(s)-1-i]) return 0;
    }
    return 1;
}

// int substring(char* s, char* t){
//     if(strlen(s) >= strlen(t)){
//         for(int i = 0; i <= strlen(s) - strlen(t) ; i++){
//             if (s[i] == t[0]){
//                 int flag = 1;
//                 for(int j = 0 ; j < strlen(t) ; j++){
//                     if(s[i+j] != t[j]){
//                         flag = 0;
//                         break;
//                     }
//                 }
//                 if (flag) return 1;
//             }
//         }
//     }

//     return 0;
// }

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

// substring인지 체크하는 함수
int substring(char *s, char *t) {
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

char** max_palindrome(char* s, int* resultSize){
    
    int len = strlen(s);
    char** result = (char**)malloc(100*sizeof(char*));
    for (int i = len; i >= 1; i--){
        int l = 0;
        int r = l + i;

        while (r <= len){
            char* substr  = slice(s, l, r);

            if (palindrome(substr)){
                int flag = 1;
                for (int j = 0; j < *resultSize; j++){
                    if (substring(result[j], substr)){
                        flag = 0;
                        break;
                    }
                }

                if (flag){
                    printf("%s\n", substr);
                    result[*resultSize] = cloneString(substr);
                    (*resultSize)++;
                    // appendStringToArray(&result, resultSize, substr);
                }
            }
            free(substr);

            r++;
            l++;
        }
    }

    return result;
}


int main(){

    char* case1 = "kabccbadzdefgfeda";
    int resultSize = 0;
    char** result1 = max_palindrome(case1, &resultSize);

    printf("[Case1]\n");
    for(int i = 0; i < resultSize; i++){
        printf("%s\n", result1[i]);
    }

    char* case2 = "kabccba dzabccbaza";
    resultSize = 0;
    char** result2 = max_palindrome(case2, &resultSize);

    printf("[Case2]\n");
    for(int i = 0; i < resultSize; i++){
        printf("%s\n", result2[i]);
    }


    // while (result1[i] != NULL) {
    //     printf("%s\n", result1[i]);
    //     i++;
    // }
    
    // printf("\n[Case2]\n");
    // char* case2 = "kabccba dzabccbaza";
    // char** result2 = max_palindrome(case2);
    // i = 0;
    // while (result2[i] != NULL) {
    //     printf("%s\n", result2[i]);
    //     i++;
    // }

// strstr()
// strcpy()
// strncpy()

}
