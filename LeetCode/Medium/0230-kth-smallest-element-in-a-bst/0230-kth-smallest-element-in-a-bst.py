# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def BFS(self, root):

        result = list()

        if root:

            q = deque()
            q.append(root)
            result.append(root.val)

            while q:
                
                cntNode = q.popleft()

                    
                if cntNode.left is not None:
                    result.append(cntNode.left.val)
                    q.append(cntNode.left)

                if cntNode.right is not None:
                    result.append(cntNode.right.val)
                    q.append(cntNode.right)
        
        result.sort()
        
        return result


    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        
        BFSresult = self.BFS(root)

        return BFSresult[k-1]

        