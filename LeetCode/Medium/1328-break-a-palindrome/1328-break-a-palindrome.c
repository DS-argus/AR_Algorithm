int isPalindrome_str(char *str, int start, int end) {
    // 주어진 문자열에서 start, end까지가 palindrome인가?
    // Example
    //      isPalindrome(s, 0, strlen(s)-1) : s 전체가 palindrome인가?
    while (start < end) {
        if (str[start++] != str[end--]) return 0;
    }
    return 1;
}

char* breakPalindrome(char* palindrome) {
    int len = strlen(palindrome);
    
    char * temp1 = (char *)malloc(len + 1); 
    strcpy(temp1, palindrome);
    
    char * temp2 = (char *)malloc(len + 1);
    strcpy(temp2, palindrome);


    if (len==1) return "";

    int checker1 = 0;
    for (int i = 0; i < len; i++) {
        if (temp1[i] == 'a') {
            continue;
        } else {
            char temp = temp1[i];
            temp1[i] = 'a';
            if (isPalindrome_str(temp1, 0, len-1)){
                temp1[i] = temp;
            }else{
                checker1 = 1;
                break;
            }
        }
    }

    int checker2 = 0;
    for (int i = len-1; i >= 0; i--) {
        if (temp2[i] != 'z'){
            temp2[i]++;
            checker2 = 1;
            break;
        }
    }

    if (checker1 && checker2){
        if (temp1 < temp2) return temp1;
        return temp2;
    }else if(checker1){
        return temp1;
    }else{
        return temp2;
    }

}