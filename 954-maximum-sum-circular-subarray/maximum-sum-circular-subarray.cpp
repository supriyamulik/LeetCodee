class Solution {
public:
    int kadaneMax(vector<int>& nums, int n)
    {
        int maxi = nums[0];
        int sum = nums[0];
        for(int i=1; i<n; i++)
        {
            sum = max(sum+nums[i], nums[i]);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
    int kadaneMin(vector<int>& nums, int n)
    {
        int mini = nums[0];
        int sum = nums[0];
        for(int i=1; i<n; i++)
        {
            sum = min(sum+nums[i], nums[i]);
            mini = min(mini, sum);
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++)
        {
            totalSum += nums[i];
        }
        int maxSum = kadaneMax(nums, n);
        int minSum = kadaneMin(nums, n);

        int circularSum = totalSum - minSum;
        if(maxSum > 0) return max(maxSum, circularSum);
        return maxSum;
    }
};