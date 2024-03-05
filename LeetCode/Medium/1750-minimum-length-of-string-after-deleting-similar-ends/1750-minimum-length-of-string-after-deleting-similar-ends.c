#include <string.h>

int minimumLength(char* s) {
    int ll = 0;
    int rr = strlen(s); // Get the length of the string.

    while (ll+1 < rr && s[ll] == s[rr - 1]) {
        char ch = s[ll];
        int lr = ll, rl = rr;

        // Increment lr until a different character or the end of the substring is found.
        while (lr+1 < rl && s[lr] == ch) {
            lr++;
        }

        // Decrement rl until a different character or the start of the substring is found.
        while (rl > lr && s[rl - 1] == ch) {
            rl--;
        }

        // Update ll and rr for the next iteration or result calculation.
        ll = lr;
        rr = rl;
    }

    // The length of the remaining string is rr - ll.
    return rr - ll;
}
