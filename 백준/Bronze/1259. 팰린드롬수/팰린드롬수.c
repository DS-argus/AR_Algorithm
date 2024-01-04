#include <stdio.h>
#include <string.h>

int main() {
    while (1) {
        char s1[10];
        scanf("%s", s1); // Limit input to 9 characters
        if (strcmp(s1, "0") == 0) break;

        int l = strlen(s1);

        int flag = 1;

        for (int i = 0; i < (l + 1) / 2; i++) {
            if (s1[i] != s1[l - i - 1]) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            printf("%s\n", "yes");
        } else {
            printf("%s\n", "no");
        }
    }
}
