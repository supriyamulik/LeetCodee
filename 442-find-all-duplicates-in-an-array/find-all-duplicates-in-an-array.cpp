class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        for (auto& entry : mpp) {
            if (entry.second >= 2) {
                ans.push_back(entry.first);
            }
        }
        return ans;
    }
};