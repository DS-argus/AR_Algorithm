class Solution:
    def create_string(self, s, pal, v):
        res=[]
        for i in range(len(s)):
            if 1<<i&v:
                res.append(s[i])
        if res==res[::-1]:
            pal[v]=len(res)
	
    def maxProduct(self, s: str) -> int:
        pal, n = dict(), len(s)
        for i in range(1, pow(2,n)):
            self.create_string(s, pal, i)
        
        print(pal)
        
        res=0
        for x in pal:
            for y in pal:
                if not x&y:
                    res=max(res,pal[x]*pal[y])
        return res