class Solution {
public:
    static bool compare(string &a, string &b)
    {
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> numStr;
        for(int num : nums)
        {
            numStr.push_back(to_string(num));
        }
        sort(numStr.begin(), numStr.end(), compare); // to use this customized compare the function should be a static function
        string result;
        for(string &s : numStr)
        {
            result+=s;
        }
        if (result[0] == '0') return "0";
        return result;
    }
};