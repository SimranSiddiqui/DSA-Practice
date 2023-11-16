class Solution {
public:
    unordered_map<string, int> mp;
    
    string solve(int n, string curr)
    {
        if(n==0)
        {
            if(mp.find(curr) == mp.end())
                return curr;
            return "";
        }
        
        string ans = "";
        
        curr.push_back('0');
        ans = solve(n-1, curr);
        if(ans != "")
            return ans;
        
        curr.pop_back();
        curr.push_back('1');
        ans = solve(n-1, curr);
        
        return ans;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        n = nums[0].length();
        string curr = "";
        return solve(n, curr);
    }
};