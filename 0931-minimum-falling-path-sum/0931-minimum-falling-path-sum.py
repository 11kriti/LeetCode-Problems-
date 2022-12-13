class Solution:
    def minFallingPathSum(self, matrix: list[list[int]]) -> int:

        m = len(matrix)

        matrix = [[inf]+x+[inf] for x in matrix]            # <–– apply some rails to the matrix, whichpreclude  
                                                            #     the need for checking if we are off the board
        for i in range(m-2,-1,-1):
            for j in (range(1,m+1)):
                matrix[i][j]+= min(matrix[i+1][j-1:j+2])    # <–– sliding window
                
        return min(matrix[0])