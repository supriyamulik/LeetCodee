class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        // approach is to first traverse the boundary of the matrix and mark visited if any 0 at found while traversing the boundary push it into the queue now until the queu is empty pop it and look left right up down around that if any 0 fornd and not viisted previously then push it into the queue and mark it as visited after this step we will get all the boundary and boundary connected elemets that cannot be made X so now at last traverse again the matrix and make  all the 0 that re not viisted yet to X 
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<int, int>> q;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i=0; i<n; i++)
        {
            if(board[0][i] == 'O' && !visited[0][i])
            {
                visited[0][i] = 1;
                q.push({0, i});
            }
            if(board[m-1][i] == 'O' && !visited[m-1][i])
            {
                visited[m-1][i] = 1;
                q.push({m-1, i});
            }
        }

        for(int i=0; i<m; i++)
        {
            if(board[i][0] == 'O' && !visited[i][0])
            {
                visited[i][0] = 1;
                q.push({i, 0});
            }
            if(board[i][n-1] == 'O' && !visited[i][n-1])
            {
                visited[i][n-1] = 1;
                q.push({i, n-1});
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

                if(nr >= 0 && nr < m && 
                   nc >= 0 && nc < n &&
                   !visited[nr][nc] &&
                   board[nr][nc] == 'O')
                   {
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                   }
            }
        }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j] == 'O' && !visited[i][j])
            {
                board[i][j] = 'X';
            }
        }
    }
  }
};