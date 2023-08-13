# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def reverseSubtree(self, root):
        if root is not None:
            ptr = root
            
            ptr.right, ptr.left = ptr.left, ptr.right
            # temp = ptr.right
            # ptr.right = ptr.left
            # ptr.left = temp

            self.reverseSubtree(ptr.left)
            self.reverseSubtree(ptr.right)

    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        self.reverseSubtree(root)

        return root