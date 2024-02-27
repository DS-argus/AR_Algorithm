def str_perm(s):

    #모든 permutation 만들고
    slist = [s[i] for i in range(len(s))]
    result = create_permutations(slist)

    #중복제거
    result = list(set(result))

    #Sort
    result.sort()

    return result

def create_permutations(slist):
    result = []
    if len(slist) == 1:
        return slist
    
    or_list = slist.copy()
    for s in or_list:
        slist = or_list.copy()
        slist.remove(s)
        L = create_permutations(slist)
        for l in L:
            result.append(s+l)


    return result


if __name__ == "__main__":

    print(str_perm("abc"))
    print(str_perm("abb"))

