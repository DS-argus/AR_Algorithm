#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* remove_repeats(const char* s) {
    // Allocate a table to keep track of character counts
    int charCount[256] = {0}; // Assuming ASCII charset

    // First pass: Count occurrences of each character
    for (int i = 0; s[i] != '\0'; i++) {
        charCount[(unsigned char)s[i]]++;
    }

    // Allocate memory for the new string, which can be at most the length of the original string + 1 for null terminator
    char* result = (char*)malloc(strlen(s) + 1);

    // Second pass: Copy only characters that appear exactly once
    int j = 0; // Index for the new string
    for (int i = 0; s[i] != '\0'; i++) {
        if (charCount[(unsigned char)s[i]] >= 1) {
            result[j++] = s[i];
            charCount[(unsigned char)s[i]] = -1;
        }
    }
    result[j] = '\0'; // Null-terminate the new string

    return result;
}
// Function to check if a character is adjacent to any character in a substring
// based on the original string 's'.
int is_adjacent(const char* s, char bf, char ch) {
    int len_s = strlen(s);
    for(int i = 0; i < len_s; i++) {
        if(s[i] == bf) {
            // Check previous and next character in 's' for adjacency
            if(i > 0 && ch == s[i-1]) return 1;
            if(i < len_s-1 && ch == s[i+1]) return 1;
        }
    }
    return 0;
}

// Recursive function to generate combinations and count valid ones.
void generate_combinations(const char* s, char* buffer, int level, const char* remaining) {

    int len = strlen(remaining);
    if(len == 0) {
        buffer[level] = '\0';
        return;
    }

    for(int i = 0; i < len; i++) {
        if(level > 0 && is_adjacent(s, buffer[strlen(buffer)-1], remaining[i])) continue;

        // Add current character to buffer and call recursively
        buffer[level] = remaining[i];
        char new_remaining[strlen(remaining)];
        strncpy(new_remaining, remaining, i);   // i-1 까지 복사
        new_remaining[i] = '\0'; // Null-terminate the string
        strcat(new_remaining, remaining + i + 1); // Skip the current character i+1부터 붙이기?

        generate_combinations(s, buffer, level + 1, new_remaining);
        if (strlen(buffer) == strlen(s)) return;
        
        buffer[level] = '\0';
    }
}

char* foo(const char* s) {
    char* buffer = (char*)malloc((strlen(s)+1) * sizeof(char));
    generate_combinations(s, buffer, 0, s);

    if(strlen(buffer) == 0){
        return "";
    }else{
        return buffer;
    }
}

char* bar(const char* s) {
    s = remove_repeats(s);
    char* buffer = (char*)malloc((strlen(s)+1) * sizeof(char));
    generate_combinations(s, buffer, 0, s);

    if(strlen(buffer) == 0){
        return "";
    }else{
        return buffer;
    }
}


int main() {
    printf("%s\n", foo("abcde"));
    printf("%s\n", foo("abc"));
    printf("%s\n", foo(""));
    printf("%s\n", foo("abccde"));
    printf("%s\n", foo("abcdcef"));
    printf("=================\n");
    printf("%s\n", bar("abcde"));
    printf("%s\n", bar("abc"));
    printf("%s\n", bar(""));
    printf("%s\n", bar("abccde"));
    printf("%s\n", bar("abcdcef"));

    return 0;
}