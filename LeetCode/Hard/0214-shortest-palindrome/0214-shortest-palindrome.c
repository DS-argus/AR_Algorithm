bool isPalindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start++] != str[end--]) return false;
    }
    return true;
}


char* shortestPalindrome(char* s) {
    if (strlen(s)<=1 || isPalindrome(s, 0, strlen(s))) return s;
    
    int end;
    for(end = strlen(s)-1; end >= 0; end--){
        if (isPalindrome(s, 0, end)) break;
    }

    char * result = malloc(sizeof(char) * strlen(s)-end+1+strlen(s));

    for(int i = 0; i < strlen(s)-1-end; i++){
        result[i] = s[strlen(s)-1-i];
    }
    
    result[strlen(s)-end-1] = '\0';
    
    strcat(result, s);
    
    return result;

}