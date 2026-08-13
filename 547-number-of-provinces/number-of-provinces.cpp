class Solution {
private:
    void dfs(int node, vector<int> adjList[], vector<int>& visited)
    {
        visited[node] = 1;
        for(auto it : adjList[node])
        {
            if(!visited[it])
            {
                dfs(it, adjList, visited);
            }
        }
    }
    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n];
        int count = 0;
        //Step 1 Convert the adj matrix to List
        for(int i=0; i<isConnected.size(); i++)
        {
            for(int j=0; j<isConnected.size(); j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                } 
            }
        }

        // step 2 is to create a visited array and mark every one as 0 and then strt the dfs traversal
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++)
        {
            if(!visited[i]){
                count++;
                dfs(i, adjList, visited);
            }
        }
        return count;
    }
};