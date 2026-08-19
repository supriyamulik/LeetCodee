class Solution {
public:
   bool dfs(int& node, vector<vector<int>>& adjList, vector<int>& state, vector<int> &ans)
    {
        if(state[node] == 1) return true;
        if(state[node] == 2) return false;

        state[node] = 1;
        for(int neigh : adjList[node])
        {
            if(dfs(neigh, adjList, state, ans)) return true;
        }
        state[node] = 2;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adjList(numCourses);
        vector<int> ans;
        for(auto &p : prerequisites)
        {
            adjList[p[1]].push_back(p[0]);
        }
        vector<int> state(numCourses,0);
        for(int i = 0; i<numCourses; i++)
        {
            if(state[i] == 0 && dfs(i, adjList, state, ans)) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};