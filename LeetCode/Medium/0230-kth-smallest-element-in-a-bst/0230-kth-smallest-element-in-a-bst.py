# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        
        result = list()

        if root:

            q = deque()
            q.append(root)

            while q:
                
                cntNode = q.popleft()

                if cntNode is not None:
                    result.append(cntNode.val)
                    q.append(cntNode.left)
                    q.append(cntNode.right)
        
        result.sort()

        return result[k-1]

