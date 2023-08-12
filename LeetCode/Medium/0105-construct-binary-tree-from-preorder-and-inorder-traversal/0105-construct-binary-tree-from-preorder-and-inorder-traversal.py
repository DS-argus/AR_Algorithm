# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTreeHelper(self, preorder, inorder, root):

        if len(preorder) == 0:
            return root
        
        value = preorder[0]
        
        root = TreeNode(value)

        idx = inorder.index(value)

        inorder_leftSubtree = inorder[:idx]
        inorder_rightSubtree = inorder[idx+1:]

        preorder_leftSubtree = preorder[1:len(inorder_leftSubtree)+1]
        preorder_rightSubtree = preorder[len(inorder_leftSubtree)+1:]

        root.left = self.buildTreeHelper(preorder_leftSubtree, inorder_leftSubtree, root.left)
        root.right = self.buildTreeHelper(preorder_rightSubtree, inorder_rightSubtree, root.right)

        return root



    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:

        ## preorder : root->left->right
        ## inorder : left->root->right

        root = self.buildTreeHelper(preorder, inorder, None)

        return root