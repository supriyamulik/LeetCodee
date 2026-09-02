class Solution {
public:
    int func(int index, vector<int>& nums, vector<int>& dp)
    {
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];

        int maxSum = INT_MIN;
        int rob = nums[index]+func(index-2,nums, dp);
        int skip = func(index-1,nums, dp);
        
        maxSum = max(rob, skip);
        return dp[index] = maxSum;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return func(n-1, nums, dp);
    }
};