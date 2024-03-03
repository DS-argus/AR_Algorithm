long long charToLongLong(char *str) {
    long long n;
    sscanf(str, "%lld", &n);
    return n;
}

int isPalindrome_long_long(long long n) {
    long long reverse = 0, temp = n;

    while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return n == reverse;
}

// Helper function to generate next palindrome
long long nextPalindrome(long long n, int odd) {
    long long res = n;
    
    // If odd, skip the last digit of n when creating the palindrome
    if (odd) {
        n /= 10;
    }
    
    while (n > 0) {
        res = res * 10 + (n % 10);
        n /= 10;
    }
    return res;
}

int superpalindromesInRange(char* left, char* right) {
    long long l = charToLongLong(left);
    long long r = charToLongLong(right);
    int cnt = 0;

    // Start generating palindromes
    for (int odd = 0; odd <= 1; odd++) {
        long long n = 1;
        long long pal = nextPalindrome(n, odd);
        while (pal <= sqrt(r)) {
            if (pal >= sqrt(l) && isPalindrome_long_long(pal * pal)) {
                cnt++;
            }
            n++;
            pal = nextPalindrome(n, odd);
        }
    }

    return cnt;
}