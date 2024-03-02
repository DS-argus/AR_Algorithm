// Function to find the longest palindromic subsequence length
int longestPalindromeSubseq(char *s) {
    int len = strlen(s);
    int dp[len][len]; // DP table

    // Initialize DP table
    memset(dp, 0, sizeof(dp));

    // Every single character is a palindrome of length 1
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }

    // Fill DP table
    for (int subLen = 2; subLen <= len; subLen++) {
        for (int start = 0; start <= len - subLen; start++) {
            int end = start + subLen - 1;
            
            if (s[start] == s[end] && subLen == 2) {
                dp[start][end] = 2;
            } else if (s[start] == s[end]) {
                dp[start][end] = dp[start + 1][end - 1] + 2;
            } else {
                dp[start][end] = (dp[start + 1][end] > dp[start][end - 1]) ? dp[start + 1][end] : dp[start][end - 1];
            }
        }
    }

    return dp[0][len - 1];
}
