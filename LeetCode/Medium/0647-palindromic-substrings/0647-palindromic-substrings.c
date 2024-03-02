// Improved palindrome checking function
int isPalindrome_str(const char *str, int start, int end) {
    while (start < end) {
        if (str[start++] != str[end--]) return 0;
    }
    return 1;
}

// Optimized function to count palindrome substrings
int countSubstrings(char* s) {
    int count = 0;
    int length = strlen(s); // Only call strlen once

    for (int start = 0; start < length; start++) {
        for (int end = start; end < length; end++) {
            if (isPalindrome_str(s, start, end)) {
                count++;
            }
        }
    }
    
    return count;
}