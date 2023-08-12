# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def BFS(self, root):

        result = dict()

        if root:

            idx = 0

            q = deque()
            q.append(root)
            result[root.val] = idx

            while q:
                
                cntNode = q.popleft()

                if cntNode.left is None:
                    idx += 1
                    result[-1] = idx
                else:
                    idx += 1
                    result[cntNode.left.val] = idx
                    q.append(cntNode.left)

                if cntNode.right is None:
                    idx += 1
                    result[-1] = idx
                else:
                    idx += 1
                    result[cntNode.right.val] = idx
                    q.append(cntNode.right)
                
        return result


    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        
        BFSresult = self.BFS(root)
        value = list(BFSresult.keys())
        value.sort()

        return value[k]

        