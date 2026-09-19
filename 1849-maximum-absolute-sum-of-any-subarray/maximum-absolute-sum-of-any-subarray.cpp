class Solution {
public:
    int kadaneMax(vector<int>& nums, int n)
    {
        int sum = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<n; i++)
        {
            sum = max(nums[i], sum+nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
    int kadaneMin(vector<int>& nums, int n)
    {
        int sum = nums[0];
        int minSum = nums[0];

        for(int i=1; i<n; i++)
        {
            sum = min(nums[i], sum+nums[i]);
            minSum = min(sum, minSum);
        } 
        return minSum;
    }
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int n = nums.size();
        int maxii = 0;
        int maxSum = kadaneMax(nums, n);
        int minSum = kadaneMin(nums, n);

        maxii = max(abs(maxSum), abs(minSum));
        return maxii;
    }
};