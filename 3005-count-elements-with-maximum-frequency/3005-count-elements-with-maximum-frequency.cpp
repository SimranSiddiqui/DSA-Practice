class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101, 0);
        
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        
        sort(freq.begin(), freq.end());
        int val = freq[freq.size()-1];
        int ans = 0, i = freq.size() - 1;
        
        while(i>=0 && freq[i] == val)
        {
            ans += freq[i];
            i--;
        }
        
        return ans;
        
    }
};