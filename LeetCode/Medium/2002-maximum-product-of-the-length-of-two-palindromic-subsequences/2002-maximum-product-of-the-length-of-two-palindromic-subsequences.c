#define MAX_LEN 20 // Assuming a maximum length of the string

int isPalindrome(char *subseq, int len) {
    int start = 0, end = len - 1;
    while (start < end) {
        if (subseq[start++] != subseq[end--]) return 0;
    }
    return 1;
}

int maxProduct(char *s) {
    int n = strlen(s);
    int pal[1 << MAX_LEN] = {0}; // Stores lengths of palindromic subsequences
    char subseq[MAX_LEN + 1]; // Temporary storage for subsequences

    // Generate all subsequences using bit masks
    for (int mask = 1; mask < (1 << n); mask++) {
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subseq[len++] = s[i];
            }
        }
        subseq[len] = '\0'; // Null-terminate the subsequence string

        // Check if the subsequence is a palindrome
        if (isPalindrome(subseq, len)) {
            pal[mask] = len;
        }
    }

    // Find the max product of lengths of two non-overlapping palindromic subsequences
    int maxProd = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            if ((i & j) == 0 && pal[i] > 0 && pal[j] > 0) { // Ensure non-overlapping and both are palindromes
                int prod = pal[i] * pal[j];
                if (prod > maxProd) {
                    maxProd = prod;
                }
            }
        }
    }

    return maxProd;
}