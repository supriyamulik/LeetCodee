class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // 1 store the orignal color 
        int ori = image[sr][sc];
        // if it is equal to the new color do not do anythig return directly
        if(ori == color) return image;

        int n = image.size();
        int m = image[0].size();

        // taking a queue to perform bfs trversal too keep track of the orig color values
        queue<pair<int, int>> q;

        q.push({sr,sc});
        image[sr][sc] = color; // push the orig to the queue and update its color 

        // taking direction arrays to indicate the vertical and horizontal of the cell 
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty())
        {
            // taking the row nd the col from the queue 
            int r = q.front().first; 
            int c = q.front().second;
            q.pop(); 
            // checking for the vertical and horizontal if they are of the saam ecolor  
            for(int i=0; i<4; i++)
            {
                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(nrow >= 0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == ori)
                {
                    image[nrow][ncol] = color; // if yes updatiing to new color nd pushig the sr and sc to the queue to check its neighbours 
                    q.push({nrow,ncol});
                }
            }
        }
        return image; // return the result 
    }
};