#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, N;
    scanf("%d %d", &n, &N);

    int *lines = (int *)malloc(n * sizeof(int));
    int max_line = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &lines[i]);
        if (lines[i] > max_line) {
            max_line = lines[i];
        }
    }

    long long l = 1, r = max_line;
    
    while (l <= r) {
        long long mid = (l + r) / 2;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += lines[i] / mid;
        }
        
        if (sum >= N) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%d\n", r);
    
    free(lines);
    return 0;
}
