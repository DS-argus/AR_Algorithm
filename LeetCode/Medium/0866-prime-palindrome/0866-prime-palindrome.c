int isPalindrome(int n) {
    int temp = 0, n_d = n;

    while (n / 10) {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    temp = temp * 10 + n;
    return n_d == temp;
}

int isPrime(int n) {
    if (n == 1) return 0;
    
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int primePalindrome(int n) {
    if (n < 3) return 2;
    if (1e7 <= n && n <= 1e8) return 100030001;
    
    for (int i = n; i < 2e8 ; i++) {
        if (i % 2 == 0) continue;
        if (isPalindrome(i) && isPrime(i)) return i;
    }
    return 0;
}