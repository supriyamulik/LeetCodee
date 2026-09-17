class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
                unordered_map<int, int> mpp;
        long prefix = 0;
        long count = 0;
        int n = nums.size();

        mpp[0] = 1; 

        for(int i = 0; i < n; i++) {
            prefix += nums[i];

            int rem = ((prefix % k) + k) % k; 

            if(mpp.find(rem) != mpp.end()) {
                count += mpp[rem]; 
            }
            mpp[rem]++;
        }
        return count;
    }
};