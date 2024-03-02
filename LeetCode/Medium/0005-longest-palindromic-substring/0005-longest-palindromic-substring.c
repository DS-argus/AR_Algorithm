void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matrix[i][j]); // "%4d"는 숫자를 최소 네 자리로 출력합니다. 필요에 따라 조정하세요.
        }
        printf("\n"); // 각 행이 끝날 때마다 새로운 줄로 넘어갑니다.
    }
}

// C function으로 slicing을 구현
char *slice(const char *str, int start, int end) {
    int len = end - start;
    char *slice = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        slice[i] = str[start + i];
    }
    slice[len] = '\0';
    return slice;
}

char* longestPalindrome(char* s) {

    int n = strlen(s);
    int DP[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            DP[i][j] = 0;
        }
    }

    char* result;    

    // length = 1
    for (int i = 0; i < n; i++){
        DP[i][i] = 1;
    }
    int x = 0;
    int y = 1;

    // length = 2    
    for (int i = 0; i < n-1; i++){
        if (s[i]==s[i+1]){
            DP[i][i+1] = 1;
            x = i;
            y = i+2;
        }
    }

    // length > 2
    for (int len = 3; len <= n; len++){
        for (int i = 0; i <= n-len; i++){
            if ((s[i]== s[i+len-1]) && DP[i+1][i+len-2]){
                DP[i][i+len-1] = 1;
                x = i;
                y = i+len;
            }
        }
    }

    
    result = slice(s, x, y);
    
    return result;
}