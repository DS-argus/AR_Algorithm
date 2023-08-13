# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # def buildTreeHelper(self, preorder, inorder, root):

    #     if len(preorder) == 0:
    #         return root
        
    #     root = TreeNode(preorder[0])

    #     idx = inorder.index(preorder[0])

    #     inorder_leftSubtree = inorder[:idx]
    #     inorder_rightSubtree = inorder[idx+1:]

    #     preorder_leftSubtree = preorder[1:len(inorder_leftSubtree)+1]
    #     preorder_rightSubtree = preorder[len(inorder_leftSubtree)+1:]

    #     root.left = self.buildTreeHelper(preorder_leftSubtree, inorder_leftSubtree, root.left)
    #     root.right = self.buildTreeHelper(preorder_rightSubtree, inorder_rightSubtree, root.right)

    #     return root


    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:

        ## preorder : root->left->right
        ## inorder : left->root->right

        if len(preorder) == 0:
            return 
        
        root = TreeNode(preorder[0])

        idx = inorder.index(preorder[0])

        inorder_leftSubtree = inorder[:idx]
        inorder_rightSubtree = inorder[idx+1:]

        preorder_leftSubtree = preorder[1:len(inorder_leftSubtree)+1]
        preorder_rightSubtree = preorder[len(inorder_leftSubtree)+1:]

        root.left = self.buildTree(preorder_leftSubtree, inorder_leftSubtree)
        root.right = self.buildTree(preorder_rightSubtree, inorder_rightSubtree)

        return root