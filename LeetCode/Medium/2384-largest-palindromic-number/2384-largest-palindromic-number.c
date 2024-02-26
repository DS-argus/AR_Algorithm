#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* largestPalindromic(char* num) {
    int storage[10] = {0};
    
    // Count the frequency of each digit
    for (int i = 0; num[i]; i++) {
        storage[num[i] - '0']++;
    }

    // Buffers for constructing the palindrome
    char* front = (char*)malloc(strlen(num) + 1);
    char* mid = (char*)malloc(strlen(num) + 1);
    char* back = (char*)malloc(strlen(num) + 1);
    front[0] = mid[0] = back[0] = '\0'; // Initialize to empty strings

    // Build the front and back parts of the palindrome
    for (int i = 9; i >= 0; i--) {
        if((i != 0) || (i == 0 && strlen(front) != 0)){
            if ((storage[i] > 1) && storage[i] % 2 == 0) {
                for (int j = 0; j < storage[i] / 2; j++) {
                    char temp[2] = {i + '0', '\0'};
                    strcat(front, temp);
                    // Prepend to back (to avoid reversing later)
                    char tempBack[strlen(back) + 2];
                    strcpy(tempBack, temp);
                    strcat(tempBack, back);
                    strcpy(back, tempBack);
                }
            }else if(storage[i] % 2 != 0){
                char tempmid[2] = {i + '0', '\0'};
                if (strlen(mid) == 0) strcat(mid, tempmid);
                
                for (int j = 0; j < (storage[i]-1) / 2; j++) {
                    char temp[2] = {i + '0', '\0'};
                    strcat(front, temp);
                    // Prepend to back (to avoid reversing later)
                    char tempBack[strlen(back) + 2];
                    strcpy(tempBack, temp);
                    strcat(tempBack, back);
                    strcpy(back, tempBack);
                }
            }
        }    
    }

    if (strlen(front) == 0 && strlen(mid) == 0) {
        strcpy(mid, "0");
    }

    // Combine parts into the result
    char* result = (char*)malloc(strlen(num)+1);
    strcpy(result, front);
    strcat(result, mid);
    strcat(result, back);

    free(front);
    free(back);

    return result;
}
