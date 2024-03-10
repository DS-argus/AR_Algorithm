from typing import Union

def isPalindrome(s: Union[str, int]) -> bool:
    """
    주어진 문자열 혹은 int가 Palindrome인가?
    """

    if isinstance(s, str):
        return s == s[::-1]
    
    elif isinstance(s, int):
        reverse = 0
        temp = s 
        while (temp != 0): 
            reverse = (reverse * 10) + (temp % 10) 
            temp = temp // 10
        
        return (reverse == s) # if it is true then it will return 1; 
    
def getDivisions(s: str, start: int, path: list, results: list) -> None:
    """
    주어진 str에 대한 모든 분할 생성
    len(s) = n일 때, len(divisions) = 2**(n-1)
    Example:
        s = "abc"
        getDivisions(s, 0, [], divisions:=[])
        print(divisions) : [['abc'], ['a', 'bc'], ['a', 'b', 'c'], ['ab', 'b']]
    """
    # If we've reached the end of the string, add the current partition to the results
    if start == len(s):
        results.append(path[:])
        return
    
    for end in range(start + 1, len(s) + 1):
        # If the current segment is a palindrome, recurse with this segment added to the path
        getDivisions(s, end, path + [s[start:end]], results)

def getSubstrings(s: str, start: int, results: list, k: int) -> None:
    """
    문자열 s에 대해 길이가 k(<len(s))인 substrings 생성
    Example:
        s = "abcede"
        getSubstrings(s, 0, substrings:=[], 3)
        print(substrings) : ['cde', 'bde', 'bce', 'bcd', 'ade', 'ace', 'acd', 'abe', 'abd', 'abc']
    """

    if len(s) == k:
        results.append(s)
        return

    for end in range(start, len(s)):
        substring = s[:end] + s[end+1:]
        getSubstrings(substring, end, results, k)

def binarysearch(nums: list[int], target: int) -> int:
    l, r = 0, len(nums) - 1

    while l < r:
        mid = l + (r - l) // 2
        if nums[mid] >= target:
            r = mid
        else:
            l = mid + 1

    if nums[l] != target:
        return -1
    return l

def merge_sort(arr: list[int]) -> None:
    def sort(low, high):
        if high - low < 2:
            return
        mid = (low + high) // 2
        sort(low, mid)
        sort(mid, high)
        merge(low, mid, high)

    def merge(low, mid, high):
        temp = []
        l, h = low, mid

        while l < mid and h < high:
            if arr[l] < arr[h]:
                temp.append(arr[l])
                l += 1
            else:
                temp.append(arr[h])
                h += 1

        while l < mid:
            temp.append(arr[l])
            l += 1
        while h < high:
            temp.append(arr[h])
            h += 1

        for i in range(low, high):
            arr[i] = temp[i - low]

    return sort(0, len(arr))

class GNode:

    def __init__(self, id, color="W", d=0, p=None) -> None:
        self.id = id
        self.color = color
        self.distance = d
        self.parent = p
    
    def __str__(self) -> str:
        return self.id

def BFS(G: dict, start: GNode) -> list:
    result = []
    visited = set()
    queue = [start]
    visited.add(start.id)

    while queue:
        node = queue.pop(0)
        result.append(node.id)
        
        for neighbor in G[node]:
            if neighbor.id not in visited:
                visited.add(neighbor.id) 
                queue.append(neighbor)
    
    return result

def DFS(G: dict, head: GNode) -> set:
    """
    Stack을 이용한 DFS 구현
    """
    visited = set()
    Stack = [head]
    
    while Stack:
        node = Stack.pop()
 
        if node not in visited:
            visited.add(node)
            Stack.extend(G[head])
                
    return visited

def DFS_all_paths(G: dict, start: GNode) -> list[list]:
    """
    Stack을 이용한 DFS로 모든 Path return
    """
    all_paths = []  # Store all paths
    stack = [(start, [start.id])]  # Stack stores tuples of (node, current path)

    while stack:
        (node, path) = stack.pop()

        if all(n.id in path for n in G[node]):
            all_paths.append(path)

        for neighbor in G[node]:
            if neighbor.id not in path:  # Avoid cycles by checking if neighbor is already in path
                new_path = path + [neighbor.id]
                stack.append((neighbor, new_path))
            
    return all_paths

class Node():
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BST():
    def __init__(self, num_list):
        self.root = None
        self.__buildBST(num_list)

    def __buildBST(self, num_list):

        # Build binary search tree by inserting values from num_list one by one in order starting from the front.
        # There are no duplicate values in num_list.

        if not num_list:
            return
        self.root = Node(num_list.pop(0))

        for num in num_list:
            curNode = self.root
            while curNode:
                if num < curNode.val:
                    if not curNode.left:
                        curNode.left = Node(num)
                        break
                    curNode = curNode.left
                elif num > curNode.val:
                    if not curNode.right:
                        curNode.right = Node(num)
                        break
                    curNode = curNode.right
                else:
                    print("This node already exists")
                    break


## Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
def permute(nums: list[int]) -> list[list[int]]:
    result = []
    permutation(nums, [], result)
    return result

def permutation(nums: list[int], path: list[int], result: list[list[int]]) -> None:
    if len(nums) == 0:
        result.append(path)
        return

    for i in range(len(nums)):
        permutation(nums[:i] + nums[i+1:], path + [nums[i]], result)


if __name__ == "__main__":
    print("[getDivisions]")
    getDivisions("abc", 0, [], results:=[])
    print(results)
    print("==================================")
    print("[getSubstrings]")
    getSubstrings("abcede", 0, substrings:=[], 3)
    print(substrings, len(substrings))
    
    print("==================================")
    # permutation example
    print("[permute]")
    print(permute([1, 2, 3]))
    print(permute([0, 1]))
    print(permute([1]))
    print(permute([1, 2, 3, 4]))
    print("==================================")