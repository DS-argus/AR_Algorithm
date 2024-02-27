#include <stdio.h>
#include <string.h>

int isPalindrome(char* s){
    int l = strlen(s);

    for(int i = 0; i<l/2+1; i++){
        if (s[i] != s[l-1-i]) return 0;
    }
    return 1;
}


void remove_letter(char* s, int start, int* result_len, char* result){
    
    int l = strlen(s);

    //palindrome이면 이전에 체크했을것이고 더 제거할 필요 없음(길이 1개짜리도 여기에 포함)
    if (isPalindrome(s)){
        // 만약 현재 palindrome이 더 길다면 결과 업데이트
        if (*result_len < strlen(s)){
            *result_len = strlen(s);
            strcpy(result, s);
        }
        return;
    } 

    // 중복이 없기 위해서 이전에 제거한 위치 i 보다 뒤에 있는 글자를 제거해야 함(여기에서 i번째가 됨)
    for(int i=start; i<l; i++){
        
        // s[i]를 제거한 새로운 배열만들기.
        char new_s[l];
        
        for(int j = 0; j < l-1; j++){
            if (j >= i){
                new_s[j] = s[j+1];
            }else{
                new_s[j] = s[j];
            }
        }
        
        new_s[l-1] = '\0';
        
        remove_letter(new_s, i, result_len, result);
    }

}

void maxPalindrome(char* s){

    int l = strlen(s);

    int result_len = 0;

    char* result;
    strcpy(result, s);  // 여기서 result = s하면 안되고, 이걸 없애고 remove_letter에 바로 s를 넣어도 안됨 why? -> s가 같이 바뀜
    
    remove_letter(s, 0, &result_len, result);
    
    if (result_len==0){
        printf("%d\n", 0);
    }else{
        printf("%d\n", l-result_len);
    }
    printf("%s\n", result);
}

int main(){
    char s[11];
    scanf("%s", s);
    maxPalindrome(s);
}