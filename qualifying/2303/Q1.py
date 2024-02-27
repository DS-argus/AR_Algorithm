def foo(s: str) -> str:
    
    adj_dic = create_adj_dic(s)
    combs = create_valid_combs(s, adj_dic, "", s, [])

    if combs == None or len(combs) == 0:
        return ""
    else:
        return combs[0]

def bar(s: str) -> str:
    
    adj_dic = create_adj_dic(s)
    s = "".join(adj_dic.keys())

    combs = create_valid_combs(s, adj_dic, "", s, [])

    if combs == None or len(combs) == 0:
        return ""
    else:
        return combs


def create_adj_dic(s: str) -> dict:
    
    adj_dic = dict()

    for i in range(len(s)):
        if s[i] not in adj_dic.keys():
            adj_dic[s[i]] = set()

        if i > 0:
            adj_dic[s[i]].add(s[i-1])
        
        if i < len(s)-1:
            adj_dic[s[i]].add(s[i+1])

    return adj_dic

def create_valid_combs(s: str, adj_dic: dict, sub: str, left:str, ans: list) -> list[str]:
    
    if len(sub) == len(s):
        ans.append(sub)
        return
    
    for i in range(len(left)):
    
        if not sub or left[i] not in adj_dic[sub[-1]]:
            create_valid_combs(s, adj_dic, sub+left[i], left[:i]+left[i+1:], ans)

    return ans

if __name__ == "__main__":

    print(foo("abcde"))
    print(foo("abc"))
    print(foo(""))
    print(foo("abccde"))
    print(foo("abcdcef"))
    print("=================")
    print(bar("abcde"))
    print(bar("abc"))
    print(bar(""))
    print(bar("abccde"))