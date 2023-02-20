class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        
        map<int, string, greater<int>> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]] = "";
        }
        
        int rank = 1;
        for(auto it : mp)
        {
            if(rank == 1)
            {
                mp[it.first] = "Gold Medal";
            }
            else if(rank == 2)
            {
                mp[it.first] = "Silver Medal"; 
            }
            else if(rank == 3)
            {
                mp[it.first] = "Bronze Medal";
            }
            else
            {
                mp[it.first] = to_string(rank);
            }
            
            rank++;
        }
        
        for(int i=0;i<n;i++)
        {
            ans.push_back(mp[nums[i]]);
        }
        
        return ans;
    }
};