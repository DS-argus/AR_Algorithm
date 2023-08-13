# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def reverseSubtree(self, root):
        if root is not None:
            
            root.right, root.left = root.left, root.right

            self.reverseSubtree(root.left)
            self.reverseSubtree(root.right)

    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        self.reverseSubtree(root)

        return root