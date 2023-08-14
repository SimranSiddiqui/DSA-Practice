class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end(), [&](auto &a, auto &b){
            if(a.length() == b.length())
                return a < b;
            return a.length() < b.length();
        });
        
        int i = n-1;
        while(k-- > 1)
        {
            i--;
        }
        
        return nums[i];
    }
};