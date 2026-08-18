// here if we found 1 thaat is a land we have to look for all directions and go to the depth until there is land and matk it as visited and count thata land so using dfs here. As well as dfs is esy and dors not need additionl ds to keep the track nd lso here we can use the orignal grid as the visited so no extra spce needed.

// pprach is whenever we get a 1 we call the dfs funtion in dfs we mark that node as 0 and traverse in all 4 directions recursiverly and when the program comes back to the main fter the recursive call we increment the count and check for next cells..
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
