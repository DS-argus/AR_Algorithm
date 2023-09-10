class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        // 결과를 담을 vector
        vector<int> spiral;

        // 가독성용
        int row = matrix.size(), col = matrix[0].size();

        // matrix index 값
        int r = 0, c = 0;

        // 움직이는 방향 순서대로 queue에 삽입
        int nextMove = 0;
        // spiral에 모든 값이 들어갈 때까지 반복
        while (spiral.size() < row*col){
            
            // 현재 matrix 값 spiral에 넣고 101로 값 바꿔서 방문 표시
            // 101 확인하는 건 밑에서 방향 바뀔 때 같은 위치 값 넣지 않기 위해서
            if (matrix[r][c] != 101){
                spiral.push_back(matrix[r][c]);
                matrix[r][c] = 101;
            }

            // // 다음에 움직여야할 방향 확인
            // string nextMove = q.front();

            // 만약 해당 방향으로 움직일 수 있다면(matrix 범위 안이고 방문안했으면)
            // index를 해당 방향으로 이동
            if (nextMove%4 == 0 && c+1<col && matrix[r][c+1]!=101){
                c++;
            }else if (nextMove%4 == 1 && r+1<row && matrix[r+1][c]!=101){
                r++;
            }else if (nextMove%4 == 2 && c-1>=0 && matrix[r][c-1]!=101){
                c--;
            }else if (nextMove%4 == 3 && r-1>=0 && matrix[r-1][c]!=101){
                r--;
            
            // 만약 해당 방향으로 이동이 불가능하면 다음 방향으로 이동해야하니 
            // q에서 제거해주고 다시 맨 뒤로 넣어줌(언제나 right->down->left->up 방향이니)
            }else{
                nextMove++;
            }
        }
        return spiral;
    }

};