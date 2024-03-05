class Solution:
    def minimumLength(self, s: str) -> int:

        ll, rr = 0, len(s)

        while ll < rr - 1 and s[ll] == s[rr-1]:
            
            char = s[ll]
            lr, rl = ll, rr

            while s[lr] == char and lr+1 < len(s):
                lr += 1
            
            while s[rl-1] == char and rl > 0:
                rl -= 1
            
            s = s[lr:rl]
            
            ll, rr = 0, len(s)

        return len(s)
        