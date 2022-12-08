# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1, root2):
        
        def dfs(n):
            if not (n.left or n.right) : yield n.val
            if n.left                  : yield from dfs(n.left)
            if n.right                 : yield from dfs(n.right)

        return all(x == y for x, y in zip_longest(dfs(root1), dfs(root2)))