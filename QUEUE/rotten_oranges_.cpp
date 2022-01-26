/*
Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and
(2,1) in unit time.

Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 */

  int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int count = 0;
        queue<pair<int,int>> q;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        q.push({-1,-1});

        while(!q.empty()){
            if(q.front().first == -1 && q.front().second == -1 && q.size() == 1){
                q.pop();
                break;
            }
            else if(q.front().first == -1 && q.front().second == -1 && q.size()>1){
             count++;
             q.pop();
             q.push({-1,-1});
            }
            else{
                int i = q.front().first;
                int j = q.front().second;
                if((i-1)>=0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    q.push({i-1,j});
                }
                if((j-1)>=0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    q.push({i,j-1});
                }
                 if((j+1)<col && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    q.push({i,j+1});
                }
                if((i+1)<row && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    q.push({i+1,j});
                }
                q.pop();
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;

    }
