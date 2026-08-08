class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int boat = 0;
        while(left <= right)
        {
            int sum = people[left] + people[right];
            if(sum > limit){
                boat++;
                right--;
            }
            else if(sum <= limit)
            {
                boat++;
                left++;
                right--;
            }
        }
        return boat;
    }
};