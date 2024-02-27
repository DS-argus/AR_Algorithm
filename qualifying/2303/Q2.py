class Node:
    def __init__(self, data, next=None) -> None:
        self.data = data
        self.next = next

def print_list(s: Node):
    ans = "["
    while s:
        ans += str(s.data)

        if s.next:
            ans += ","
        
        s = s.next

    ans += "]"

    return ans

def reverse_linkedlist(s: Node):
    reversedL = Node(0)

    while s:
        new_node = Node(s.data)
        new_node.next = reversedL.next
        reversedL.next = new_node

        s = s.next

    return reversedL.next

def palindrome(s: Node):
    reversedL = reverse_linkedlist(s)

    while s and reversedL:
        if s.data != reversedL.data:
            return False
        
        s = s.next
        reversedL = reversedL.next

    return True

def sub_list(s: Node, t: Node):
    # s>t

    while s:
        temp_t = t
        if s.data == temp_t.data:
            temp_s = s
            while temp_s and temp_t:
                if temp_s.data != temp_t.data:
                    break;

                if temp_t.next is None:
                    return True
                
                temp_s = temp_s.next
                temp_t = temp_t.next

        s = s.next    
    
    return False

def get_len(s: Node):
    n = 0
    while s:
        n+=1
        s = s.next

    return n

def make_sublist(s: Node, l: int, r: int):
    n = 0
    sublist = Node(0)
    dummy = sublist
    while s:
        if n == r: break
        
        if l <= n:
            new_node = Node(s.data)
            sublist.next = new_node
            sublist = sublist.next

        n += 1

        s = s.next

    return dummy.next

def max_palindromes(s: Node):
    results = []
    n = get_len(s)

    for i in range(n, 0, -1):
        l = 0
        r = l+i

        while r <= n:
            sublist = make_sublist(s, l, r)
            if palindrome(sublist):
                flag = True
                for result in results:
                    if sub_list(result, sublist):
                        flag = False
                        break

                if flag:
                    results.append(sublist)

            l += 1
            r += 1

    ans = "["

    for result in results:
        ans +=print_list(result)
        ans += ","
    
    ans = ans[:-1] + "]"

    return ans

if __name__ == "__main__":
    N1 = Node(8)
    N2 = Node(1)
    N3 = Node(2)
    N4 = Node(3)
    N5 = Node(3)
    N6 = Node(2)
    N7 = Node(1)
    N8 = Node(0)
    N9 = Node(4)
    N10 = Node(9)
    N11 = Node(1)
    N12 = Node(2)
    N13 = Node(3)
    N14 = Node(3)
    N15 = Node(2)
    N16 = Node(1)
    N17 = Node(9)
    N18 = Node(1)


    N1.next = N2
    N2.next = N3
    N3.next = N4
    N4.next = N5
    N5.next = N6
    N6.next = N7
    N7.next = N8
    N8.next = N9
    N9.next = N10
    N10.next = N11
    N11.next = N12
    N12.next = N13
    N13.next = N14
    N14.next = N15
    N15.next = N16
    N16.next = N17
    N17.next = N18

    print(max_palindromes(N1))