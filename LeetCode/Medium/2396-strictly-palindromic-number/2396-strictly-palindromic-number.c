int isPalindrome_str(char *str, int start, int end) {
    // 주어진 문자열에서 start, end까지가 palindrome인가?
    // Example
    //      isPalindrome(s, 0, strlen(s)-1) : s 전체가 palindrome인가?
    while (start < end) {
        if (str[start++] != str[end--]) return 0;
    }
    return 1;
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char* intToChar(int n){
    char *str = (char *)malloc(12);
    sprintf(str, "%d", n);
    return str;
}

char * makeBase(int n, int base){
    char * result = (char *)malloc(n);
    int len = 0;
    while (n >= base){
        result[len] = intToChar(n % base);
        len ++;
        n = n/base;
    }

    result[len] = intToChar(n);
    result[len+1] = '\0';

    reverse(result);

    return result;
}

bool isStrictlyPalindromic(int n) {
    for (int i = 2; i < n-1 ; i++){
        char * num = makeBase(n, i);
        if (!isPalindrome_str(num, 0, strlen(num)-1)) return false;
    }
    return true;
}