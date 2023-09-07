class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rowZero;
        unordered_set<int> colZero;

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0) {
                    rowZero.insert(i);
                    colZero.insert(j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (count(rowZero.begin(), rowZero.end(), i) != 0 || count(colZero.begin(), colZero.end(), j) != 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};