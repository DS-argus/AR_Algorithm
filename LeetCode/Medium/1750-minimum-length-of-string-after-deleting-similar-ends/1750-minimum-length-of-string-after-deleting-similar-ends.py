class Solution:
    def minimumLength(self, s: str) -> int:

        ll, rr = 0, len(s)

        while ll < rr - 1 and s[ll] == s[rr-1]:
            
            char = s[ll]
            lr, rl = ll, rr

            while s[lr] == char and lr+1 < len(s):
                lr += 1
            
            while s[rl-1] == char and rl > lr:
                rl -= 1
            
            ll, rr = lr, rl

        return rr - ll

    
# int minimumLength(char* s) {
#     int ll = 0;
#     int rr = strlen(s); // Get the length of the string.

#     while (ll+1 < rr && s[ll] == s[rr - 1]) {
#         char ch = s[ll];
#         int lr = ll, rl = rr;

#         // Increment lr until a different character or the end of the substring is found.
#         while (lr+1 < rl && s[lr] == ch) {
#             lr++;
#         }

#         // Decrement rl until a different character or the start of the substring is found.
#         while (rl > lr && s[rl - 1] == ch) {
#             rl--;
#         }

#         // Update ll and rr for the next iteration or result calculation.
#         ll = lr;
#         rr = rl;
#     }

#     // The length of the remaining string is rr - ll.
#     return rr - ll;
# }