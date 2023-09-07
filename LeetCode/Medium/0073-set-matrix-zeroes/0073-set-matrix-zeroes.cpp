class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int* rowZero = new int[matrix.size()]();
        int* colZero = new int[matrix[0].size()]();
        
        for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            if (rowZero[i] == 1 && colZero[j] == 1) continue;
            if (matrix[i][j] == 0){
                rowZero[i] = 1;
                colZero[j] = 1;
            }
        }

        }

        for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
        if (rowZero[i] == 1 || colZero[j] == 1) matrix[i][j] = 0;

        delete[] rowZero;
        delete[] colZero;
    }
};