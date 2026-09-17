class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        
        prefix[0] = 0;
        for(int i=1; i<n;i++)
        {
            prefix[i] = prefix[i-1]+arr[i-1];
        }
        
        suffix[n-1] = 0;
        for(int i=n-2; i>=0; i--)
        {
            suffix[i] = suffix[i+1]+arr[i+1];
        }
        for(int i=0; i<n; i++)
        {
            if(prefix[i] == suffix[i])
            {
                return i;
            }
        }
    return -1;
    }
    
};