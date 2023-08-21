class Solution:

    def DFSHelper(self, board, i, j, word, word_idx, prev_matrix):
        r, c = len(board), len(board[0])
        
        if 0<=i<r and 0<=j<c and board[i][j] == word[word_idx] and prev_matrix[i][j] == 1:
            if word_idx == len(word)-1: 
                return 1
            
            prev_matrix[i][j] = 0   
            
            result = self.DFSHelper(board, i, j+1, word, word_idx+1, prev_matrix) + \
                     self.DFSHelper(board, i+1, j, word, word_idx+1, prev_matrix) + \
                     self.DFSHelper(board, i, j-1, word, word_idx+1, prev_matrix) + \
                     self.DFSHelper(board, i-1, j, word, word_idx+1, prev_matrix)
            
            prev_matrix[i][j] = 1

            return result 
            
        return 0

    def exist(self, board: List[List[str]], word: str) -> bool:

        r, c = len(board), len(board[0])

        for m in range(r):
            for n in range(c):
                prev_matrix = [[1 for _ in range(c+1)] for _ in range(r+1)]
                if self.DFSHelper(board, m, n, word, 0, prev_matrix):
                    return True
                
        return False
                    

                
        

