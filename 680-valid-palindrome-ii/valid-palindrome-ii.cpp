class Solution {
public:
    bool isPalindrome(int left, int right, string& s)
    {
        while(left < right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) 
    {
        string str;
        for (char c : s) 
        {
            if (isalnum(c)) str.push_back(tolower(c));
        }

        int n = str.size(); 
        int left = 0;
        int right = n-1;   

        while(left < right)
        {
             if(str[left] != str[right])
             {
                return isPalindrome(left+1, right, str) || isPalindrome(left, right-1, str);
             }
             left++;
             right--;
        } 
        return true;
    }
};