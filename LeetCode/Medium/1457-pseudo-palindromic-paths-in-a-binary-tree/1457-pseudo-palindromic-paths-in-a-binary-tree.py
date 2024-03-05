# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def canBePalindrome(self, counter):
        odd_count = sum(v % 2 for v in counter.values())
        return odd_count <= 1
        
    def dfs(self, node, counter):
        if not node:
            return 0
        
        # Update the frequency map for the current node's value
        counter[node.val] = counter.get(node.val, 0) + 1
        
        # If it's a leaf node, check if the path is pseudo-palindromic
        if not node.left and not node.right:
            result = 1 if self.canBePalindrome(counter) else 0
        else:
            # Continue DFS on left and right children
            result = self.dfs(node.left, counter) + self.dfs(node.right, counter)
        
        # Backtrack: undo the frequency map update before returning
        counter[node.val] -= 1
        
        return result

    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        
        # Start DFS from the root with an empty frequency map
        return self.dfs(root, {})
