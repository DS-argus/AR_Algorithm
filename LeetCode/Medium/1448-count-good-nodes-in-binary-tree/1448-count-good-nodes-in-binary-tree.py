# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def DFShelper(self, root, largest) -> int:
        
        if root is None: return 0

        largest = max(root.val, largest)

        return self.DFShelper(root.left, largest) + \
               self.DFShelper(root.right, largest) + \
               (root.val >= largest)


    def goodNodes(self, root: TreeNode) -> int:

        return self.DFShelper(root, root.val)