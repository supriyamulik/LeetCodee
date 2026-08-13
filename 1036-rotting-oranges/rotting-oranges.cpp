class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        //Step 1 take the grid and input all the rotten oranges into the queus as n,m and time to be 0
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntFresh = 0; // this is to keep the track that whether all the ornges are rooten at teh end or not 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;    // mark and make updtes in the visited as well
                }
                else{
                    vis[i][j] = 0;
            }
            if(grid[i][j] == 1) cntFresh++;  //counting the fresh to keep the track of so if at end there are no fresh then we can return the tm else -1
        }
    }
    // Step 2 now we hve all the rooten oranges in the queue, now using bfs we can take tehm one by one and check the 4 directeion and if fresh makee them rooten and cal the time 
    int tm = 0;
    int drow[] = {-1, 0, 1, 0};  
    int dcol[] = {0, 1, 0, -1};
    int cnt = 0;

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;

        tm = max(tm, t);
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nrow = r+drow[i];
            int ncol = c+dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow,ncol}, t+1});
                vis[nrow][ncol] = 2;
                cnt++;  // checking how many oranges we are mkking rotten from fresh;
            }
        }
    }
    if(cnt != cntFresh) return -1; // if the no of oranges made rooyen is cnt fresh then we have successfully mde all them roten else we cannot so return -1
    return tm;
    }
};