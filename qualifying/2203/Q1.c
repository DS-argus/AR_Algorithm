#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int palindrome(char* s){
    
    for(int i= 0; i < strlen(s)/2+1; i++){
        if (s[i] != s[strlen(s)-1-i]) return 0;
    }
    return 1;
}

int substring(char* s, char* t){
    if(strlen(s) >= strlen(t)){
        for(int i = 0; i <= strlen(s) - strlen(t) ; i++){
            if (s[i] == t[0]){
                int flag = 1;
                for(int j = 0 ; j < strlen(t) ; j++){
                    if(s[i+j] != t[j]){
                        flag = 0;
                        break;
                    }
                }
                if (flag) return 1;
            }
        }
    }

    return 0;
}

char** max_palindrome(char* s){

    static char* result[9999];
    int len_result = 0;
    for(int length = strlen(s); length > 0; length--){
        int l = 0;
        int r = l+length;
        while(r<=strlen(s)){
            char* substr = malloc(length + 1);
            strncpy(substr, s + l, length);
            substr[length] = '\0';

            l++;
            r++;

            if (palindrome(substr)){
                int flag = 1;

                for(int i = 0; i < len_result; i++){
                    if (substring(result[i], substr)){
                        flag = 0;
                        break;
                    }
                }

                if(flag){
                    result[len_result] = substr;
                    len_result++;
                }
            }
        }
    } 
    return result;
}


int main(){

    char* case1 = "kabccbadzdefgfeda";
    char** result1 = max_palindrome(case1);

    printf("[Case1]\n");
    int i = 0;
    while (result1[i] != NULL) {
        printf("%s\n", result1[i]);
        i++;
    }
    
    printf("\n[Case2]\n");
    char* case2 = "kabccba dzabccbaza";
    char** result2 = max_palindrome(case2);
    i = 0;
    while (result2[i] != NULL) {
        printf("%s\n", result2[i]);
        i++;
    }

// strstr()
// strcpy()
// strncpy()

}
