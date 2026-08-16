class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        // step 1 is to initialize an visited matrix, an ans matrix and a queue ds storing the index i j and the distnce
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));
        queue<pair<pair<int,int>, int>> q;

        // step 2 is to traverse the orignal matrix and find for the ones with value 0 and push them to the queue with distnce 0 and mark them as visited 
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1; 
                }
            }
        }
        // step 3 it to pop the elements until the queue is not empty set ans[x][y] = dist ans explore the neighbours in 4 directions if the neighbour is inside the bounds not visited and is 1 push the index to the queue with dis+1

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            ans[r][c] = d;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                
                if(nrow >= 0 && ncol < n && ncol >= 0 && nrow < m && visited[nrow][ncol] == 0 && mat[nrow][ncol] == 1)
                {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, d+1});
                }
            }
        }

        // return the ans
        return ans;
    }
};