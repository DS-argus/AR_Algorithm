def palindrome(s: str):
    for i in range(len(s)//2+1):
        if s[i] != s[len(s)-1-i]: return False
    return True


def substring(s: str, t: str):
    if len(s) >= len(t):
        for i in range(len(s)-len(t)+1):
            if s[i] == t[0]:
                flag = True
                for j in range(len(t)):
                    if s[i+j] != t[j]:
                        flag = False
                        break

                if flag:
                    return True                

    return False

def max_palindromes(s: str) -> list:
    result = []

    for length in range(len(s), 0, -1):
        l = 0
        r = l + length
        
        while r<=len(s):
            substr = s[l:r]
            l += 1
            r += 1
            if palindrome(substr):
                flag = True
                for palinds in result:
                    if substring(palinds, substr):
                        flag = False
                        break
            
                if flag:
                    result.append(substr)

    return result

if __name__ == "__main__":
    print("---------- 1st Example ----------")
    print("your solution  : ", max_palindromes("kabccbadzdefgfeda"))
    print("given solution : ", ["k", "abccba", "dzd", "defgfed"])
    print("---------- 2nd Example ----------")
    print("your solution  : ", max_palindromes("kabccba dzabccbaza"))
    print("given solution : ", ["k", " ", "d", "zabccbaz", "aza"])




    test_string = "abccba"
    test_sub = "bcc"
    test_palin1 = "kabccbadzdefgfeda"
    test_palin2 = "kabccba dzabccbaza"
    test_palin3 = "babab aba bab babab"
    test_palin4 = "kabccbadzdefgfeda kabccba dzabccbaza"
    test_palin5 = "cabccba"

    print("Palindrome result: ", palindrome(test_string))
    print("Substring result: ", substring(test_string, test_sub))
    print("Substring result: ", substring(test_string, "z"))

    print("Max palindrome result: ", max_palindromes(test_palin1))
    print("Max palindrome result: ", max_palindromes(test_palin2))
    print("Max palindrome result: ", max_palindromes(test_palin3))
    print("Max palindrome result: ", max_palindromes(test_palin4))
    print("Max palindrome result: ", max_palindromes(test_palin5))