class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        for(int i=0; i<n; i++)
        {
            freq[nums[i]]++;
        }
        int maxx = INT_MIN;

        if(k == 1)
        {
            for(int i=0; i<n; i++)
            {
                if(nums[i] > maxx && freq[nums[i]] == 1)
                {
                    maxx = nums[i];
                }
            }
            return (maxx == INT_MIN ? -1 : maxx);
        }
        else if(k==n)
        {
            for(int i=0; i<n; i++)
            {
                if(nums[i] > maxx){
                    maxx = nums[i];
                }
            }
            return maxx;
        }
        else{
            int firstFreq = freq[nums[0]];
            int lastFreq = freq[nums[n-1]];

           if (firstFreq == 1 && lastFreq == 1) {
                return max(nums[0], nums[n - 1]); 
            }
            else if (firstFreq == 1) {
                return nums[0];
            }
            else if (lastFreq == 1) {
                return nums[n - 1];
            }
        }
        return -1;
    }
};