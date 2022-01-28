/*
Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0
1 1 0 0
0 0 1 1
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.
*/
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>> q;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j] == 1){
	                ans[i][j] = 0;
	                q.push({i,j});
	            }
	        }
	    }

	    while(!q.empty()){
	        int i = q.front().first;
	        int j = q.front().second;

	        if((i-1)>=0 && ans[i][j]+1 < ans[i-1][j]){
	            ans[i-1][j] = ans[i][j] + 1;
	            q.push({i-1,j});
	        }
	        if((j-1)>=0 && ans[i][j]+1 < ans[i][j-1]){
	            ans[i][j-1] = ans[i][j] + 1;
	            q.push({i,j-1});
	        }
	        if((i+1)<n && ans[i][j]+1 < ans[i+1][j]){
	            ans[i+1][j] = ans[i][j] + 1;
	            q.push({i+1,j});
	        }
	         if((j+1)<m&& ans[i][j]+1 < ans[i][j+1]){
	            ans[i][j+1] = ans[i][j] + 1;
	            q.push({i,j+1});
	        }
	        q.pop();
	    }
	    return ans;
	    // Code here
	}
