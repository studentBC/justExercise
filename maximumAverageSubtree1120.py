"""
Given the root of a binary tree, return the maximum average value of a subtree of that tree. Answers within 10-5 of the actual answer will be accepted.

A subtree of a tree is any node of that tree plus all its descendants.

The average value of a tree is the sum of its values, divided by the number of nodes."""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root: Optional[TreeNode]) -> float:
        self.ans = 0
        def go (n):
            if n is None:
                return 0, 0
            sum, count = n.val, 1
            s, c =go (n.left)
            sum+=s
            count+=c
            s, c =go (n.right)
            sum+=s
            count+=c

            #print(n.val, sum, count)
            self.ans = max(self.ans, sum/count)
            return sum, count
        go(root)
        return self.ans

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maximumAverageSubtree(self, root: Optional[TreeNode]) -> float:
        self.max_avg = 0
        self.get_countandsum(root)
        return self.max_avg
        

    def get_countandsum(self,root):
        if not root:
            return [0,0]
        left = self.get_countandsum(root.left)
        right = self.get_countandsum(root.right)
        root_count = left[0] + right[0] + 1
        root_sum = left[1] + right[1] + root.val
        self.max_avg = max(self.max_avg,root_sum/root_count)
        return [root_count,root_sum]
