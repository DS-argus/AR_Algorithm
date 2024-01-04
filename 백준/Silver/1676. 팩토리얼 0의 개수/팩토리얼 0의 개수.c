#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int c1 = 0, c2 = 0;
    for (int i = 1; i <= N; i++) {
        int n = i;
        while (n > 1) {
            if (n % 2 == 0) {
                c1++;
                n /= 2;
            } else if (n % 5 == 0) {
                c2++;
                n /= 5;
            } else {
                break;
            }
        }
    }

    if (c1 < c2) {
        printf("%d", c1);
    } else {
        printf("%d", c2);
    }

    return 0;
}
