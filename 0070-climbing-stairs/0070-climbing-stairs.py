class Solution:
    def climbStairs(self, n: int, a: int = 1, b: int = 0) -> int:
        for _ in range(n): a, b = a + b, a
        return a