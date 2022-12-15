class Solution:
    def longestCommonSubsequence(self, t1: str, t2: str) -> int:
        
        @cache
        def dp(i,j):
            if i == len(t1) or j == len(t2) : return 0
            if t1[i] == t2[j] : return dp(i+1,j+1) + 1             # increase length of common subsequence or...
            else              : return max(dp(i,j+1), dp(i+1,j))   # ...propagate max length to the next position
        
        return dp(0,0)