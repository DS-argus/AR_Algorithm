int isPalindrome_str(char *str, int start, int end) {
    // 주어진 문자열에서 start, end까지가 palindrome인가?
    // Example
    //      isPalindrome(s, 0, strlen(s)-1) : s 전체가 palindrome인가?
    while (start < end) {
        if (str[start++] != str[end--]) return 0;
    }
    return 1;
}

int minCut(char *s) {
    int n = strlen(s);
    int cuts[n];
    int P[n][n]; // Boolean array for palindrome checking

    // Precompute the palindrome substrings
    for (int i = 0; i < n; i++) {
        P[i][i] = 1; // Single characters are palindromes
        cuts[i] = i; // Max cuts
    }

    // DP table 채우기
    for (int len = 2; len <= n; len++) {
        for (int start = 0; start <= n - len; start++) {
            int end = start + len - 1;
            if (len == 2)
                P[start][end] = (s[start] == s[end]);
            else
                P[start][end] = (s[start] == s[end]) && P[start + 1][end - 1];
        }
    }

    // Compute minimum cuts using dynamic programming
    for (int i = 0; i < n; i++) {
        if (P[0][i]) {
            cuts[i] = 0;
        } else {
            for (int j = 0; j < i; j++) {
                if (P[j + 1][i] && cuts[j] + 1 < cuts[i]) {
                    cuts[i] = cuts[j] + 1;
                }
            }
        }
    }

    return cuts[n - 1];
}
