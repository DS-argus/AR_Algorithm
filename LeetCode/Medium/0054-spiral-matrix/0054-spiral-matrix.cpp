class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> spiral;
        int row = matrix.size();
        int col = matrix[0].size();

        int r = 0;
        int c = 0;

        queue<string> q;
        q.push("right");
        q.push("down");
        q.push("left");
        q.push("up");

        while (spiral.size() < row*col){
            
            if (matrix[r][c] != 101){
                spiral.push_back(matrix[r][c]);
                matrix[r][c] = 101;
            }

            string nextMove = q.front();

            if (nextMove == "right"){
                if(c+1<col && matrix[r][c+1]!=101){
                    c++;
                }else{
                    q.pop();
                    q.push(nextMove);
                }
            }else if (nextMove == "down"){
                if(r+1<row && matrix[r+1][c]!=101){
                    r++;
                }else{
                    q.pop();
                    q.push(nextMove);
                }
            }else if (nextMove == "left"){
                if(c-1>=0 && matrix[r][c-1]!=101){
                    c--;
                }else{
                    q.pop();
                    q.push(nextMove);
                }
            }else{
                if(r-1>=0 && matrix[r-1][c]!=101){
                    r--;
                }else{
                    q.pop();
                    q.push(nextMove);
                }
            }
        }

        return spiral;
    }

};