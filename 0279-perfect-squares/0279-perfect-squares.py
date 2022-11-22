from math import isqrt

class Solution:
    def numSquares(self , n):
        
        if isqrt(n)**2 == n : return 1               # [1] already a square
        
        for i in range(1,isqrt(n)+1):                # [2] check pairs of squares
            if (j := n - i**2) == isqrt(j)**2:
                return 2
            
        while n % 4 == 0 : n /= 4                    # [3] well, it's maths, namely,
        if    n % 8 != 7 : return 3                  #     the Legendre's theorem
        
        return 4                                     # [4] the only remaining option