class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        # a function to check rows, columns and blocks using O(1) space
        def not_valid(digits, m=0):
            return any( 1 & (m >> int(d)) + (m := (m | (1 << int(d))))*0
                        for d in digits if d != ".")
                       
        # a generator to extract blocks
        def blocks():
            for i in range(3):
                for j in range(3):
                    yield (n for row in board[i*3:(i+1)*3] for n in row[j*3:(j+1)*3])
        
        if any(map(not_valid, board))       : return False       # [1] test rows
        if any(map(not_valid, zip(*board))) : return False       # [2] test columns
        if any(map(not_valid, blocks()))    : return False       # [3] test blocks
        
        return True