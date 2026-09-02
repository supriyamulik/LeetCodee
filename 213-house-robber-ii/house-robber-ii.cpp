//here in the problem it is given tht the houses are in a circular manner thaat is if we considered the first house then we cannot consider the last that is out window space is from 0 to n-1 and in the second case if we dont consider the first element then we can go till n


class Solution {
public:
    int robCal(vector<int>& nums, int start, int index, vector<int>& dp){
        if(index < start) return 0;
        if(dp[index] != -1) return dp[index];
        int rob = nums[index]+robCal(nums, start, index-2, dp);
        int skip = robCal(nums, start, index-1, dp);

        return dp[index] = max(rob,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        // Case 1: include first house, exclude last
        vector<int> dp1(n, -1);
        int case1 = robCal(nums, 0, n-2, dp1);
        vector<int> dp2(n, -1);
        int case2 = robCal(nums,1,n-1, dp2);
        return max(case1, case2);
    }
};