# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self) -> None:
        self.root = None

    def __invertHelp(self, curNode: TreeNode) -> TreeNode:
        if curNode:

            newNode = TreeNode(curNode.val)
            newNode.left = self.__invertHelp(curNode.right)
            newNode.right = self.__invertHelp(curNode.left)
            return newNode

    def invertTree(self, root: TreeNode) -> TreeNode:
        self.root = root
        return self.__invertHelp(self.root)