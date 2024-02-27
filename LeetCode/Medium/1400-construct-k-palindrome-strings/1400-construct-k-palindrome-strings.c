#define ALPHABET_SIZE 26

bool canConstruct(const char* s, int k) {
    int freq[ALPHABET_SIZE] = {0};
    int len = strlen(s);

    // Count frequencies of each character in the string
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    if (len < k) {
        return false;  // Not enough characters to form k palindromes
    }

    int oddCount = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
    }

    // More odd characters than k means it's impossible to form k palindromes
    return oddCount <= k;
}