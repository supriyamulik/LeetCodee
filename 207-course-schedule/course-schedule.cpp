class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adjList, vector<int>& state)
    {
        if(state[node] == 1) return true;   // is we found the nextNode already visiting then there is a cycle
        if(state[node] == 2) return false;  // all nodes are visited and no cycle was detected

        state[node] = 1; // mark the current node as visiting
        for(int neigh : adjList[node]) // take the neighbour of the current node and callm dfs
        {
            if(dfs(neigh, adjList, state)) return true;  // if the dfs is returning true tht means we have already that node visiting so returning true
        }
        state[node] = 2; // marking the node as 2 as we have completed visiting all the neighbours of tht node
        return false;    // and thus returning false
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto &p : prerequisites)
        {
            adjList[p[1]].push_back(p[0]);
        }
        vector<int> state(numCourses, 0);
        for(int i=0; i<numCourses; i++)
        {
            if(state[i] == 0 && dfs(i, adjList, state)) return false; // if dfs found  cycle it reurns a true so here return a false
        }
        return true;
    }
};