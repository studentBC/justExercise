#Each node has a depth and height. The longest path passing it has a length equals depth + height.
#
#
#When a node (Let's say D) is removed, all of its children are removed as well. So every path that goes through D stops by here. However, if D has some cousions, then the paths through these cousins will certainly be longer. We should look for the longest path among these paths through the cousins of D, which is equivalent to finding the cousin with the largest height.
#
#
#Therefore, we store the nodes according to depth. For nodes having the same depth, we sort them by their heights and only keep the top 2 of them that having the maximum depth.
#
#
#Once we 'remove' a node from queries, we locate all of its cousins, find the one with the maximum height and the job is done.
#
#If the size of cousins[depth] is 1, which means that the removed node has no cousin, so the longest resting path equals depth - 1.
#Otherwise, at least one of them is the cousin, we get its depth.
#
#Time O(N)
#Space O(N)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        depth, height = collections.defaultdict(int), collections.defaultdict(int)
        def go (node, dep):
            if not node:
                return -1
            depth[node.val] = dep
            cur = max(go(node.left, dep+1), go(node.right, dep+1))+1
            height[node.val] = cur
            return cur

        go (root, 0)
        cousin = collections.defaultdict(list)
        for val, dep in depth.items():
            cousin[dep].append((-height[val], val))
            cousin[dep].sort()
            if len(cousin[dep]) > 2:
                cousin[dep].pop()

        ans = []
        for q in queries:
            dep = depth[q]
            if len(cousin[dep]) == 1:
                ans.append(dep-1)
            elif cousin[dep][0][1] == q:
                ans.append(-cousin[dep][1][0]+dep)
            else:
                ans.append(-cousin[dep][0][0]+dep)
        return ans
