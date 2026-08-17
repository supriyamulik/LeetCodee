class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n,0));
        queue<pair<int, int>> q;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0; i<n; i++)
        {
            if(grid[0][i] == 1 && !visited[0][i])
            {
                visited[0][i] = 1;
                q.push({0,i});
            }
            if(grid[m-1][i] == 1 && !visited[m-1][i])
            {
                visited[m-1][i] = 1;
                q.push({m-1,i});
            }
        }
        
        for(int i=0; i<m; i++)
        {
            if(grid[i][0] == 1 && !visited[i][0])
            {
                visited[i][0] = 1;
                q.push({i,0});
            }
            if(grid[i][n-1] == 1 && !visited[i][n-1])
            {
                visited[i][n-1] = 1;
                q.push({i,n-1});
            }
        }

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i=0; i<4; i++)
            {
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] == 1)
                {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    count++;
                }
            }
        }
return count;
    }
};