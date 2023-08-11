# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    # def BFS(self, root):
    #     result = []

    #     q = deque()

    #     if root:
    #         q.append(root)

    #     while q:
    #         currentNode = q.popleft()
    #         result.append(currentNode.val)

    #         if currentNode.left:
    #             q.append(currentNode.left)
    #         if currentNode.right:
    #             q.append(currentNode.right)

    #     return result



    # def invertInsert(self, root, value):
    #     if root is None:
    #         root = TreeNode(value)
    #         return root
        
    #     ptr = root

    #     while ptr:
    #         if value < ptr.val:
    #             if ptr.right:
    #                 ptr = ptr.right
    #             else:
    #                 ptr.right = TreeNode(value)
    #                 break;
    #         else:
    #             if ptr.left:
    #                 ptr = ptr.left
    #             else:
    #                 ptr.left = TreeNode(value)
    #                 break

    #     return root

    def reverseSubtree(self, root):
        if root:
            ptr = root

            temp = ptr.right
            ptr.right = ptr.left
            ptr.left = temp

            self.reverseSubtree(ptr.left)
            self.reverseSubtree(ptr.right)



    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        # BFSresult = self.BFS(root)

        # if len(BFSresult) % 2 ==0 and len(BFSresult) > 0:
        #     last = BFSresult[-1]
        #     BFSresult[-1] = "null"
        #     BFSresult.append(last)            
        # print(BFSresult)
        # invertedTree = None

        # for value in BFSresult:
        #     invertedTree = self.invertInsert(invertedTree, value)
        
        # return invertedTree

        self.reverseSubtree(root)

        return root