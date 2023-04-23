# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        ls = dict()
        def go(node, level):
            if node is None:
                return
            if level in ls.keys():
                ls[level].append(node.val)
            else:
                ls[level] = [node.val]
            go(node.left, level+1)
            go(node.right, level+1)
        go(root, 0)
        ans = []
        for (k, v) in ls.items():
            ans.append(sum(v)/len(v))
        return ans


