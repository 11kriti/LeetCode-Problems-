# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n, s=1):
        
        while s <= n:
            m = (n + s) // 2          # [1] Take the middle point...
            g = guess(m)              # [2] ...and guess!
            if g == 0 : return m      # [3] Yay, we found the number!
            if g < 0  : n = m - 1     # [4] Nope, it's smaller...
            if g > 0  : s = m + 1     # [5] ...or larger.