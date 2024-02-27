

def smallest_pos_int(arr: list) -> int:
    pos = set(arr)
    # pos = [num for num in arr if num > 0]
    
    ans = len(pos)+1
    for i in range(1, ans):
        if i not in pos:
            ans = i
            break

    return ans



if __name__ == "__main__":
    
    arr1 = [4, 7, -1, 1, 2]
    arr2 = [100, 101, 102]
    arr3 = [3, 2, 1, 0, -1]
    arr4 = [5, -1, 2, 4, 1, 3]

    print(f"Answer 1 : {smallest_pos_int(arr1)}")   # 3
    print(f"Answer 2 : {smallest_pos_int(arr2)}")   # 1
    print(f"Answer 3 : {smallest_pos_int(arr3)}")   # 4
    print(f"Answer 4 : {smallest_pos_int(arr4)}")   # 6