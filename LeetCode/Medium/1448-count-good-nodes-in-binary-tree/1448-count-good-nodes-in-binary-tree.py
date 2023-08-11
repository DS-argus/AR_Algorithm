# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def DFShelper(self, root, largest) -> int:
        
        if root is None:
            return 0

        if root.val >= largest:

            largest = root.val

            return self.DFShelper(root.left, largest) + self.DFShelper(root.right, largest) + 1

        else:

            return self.DFShelper(root.left, largest) + self.DFShelper(root.right, largest) 


    def goodNodes(self, root: TreeNode) -> int:

        count = 0
        largest = root.val
        count = self.DFShelper(root, largest)

        return count
