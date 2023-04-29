class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int, int> mp;
        vector<int> ans;
        
        for(int i=0,j=0;j<n;)
        {
            if(j<k)
            {
                if(nums[j] < 0)
                mp[nums[j]]++;
                j++;
            }
            else 
            {
                int temp = x;
                int mini = 0;
                
                for(auto it : mp)
                {
                    if(temp - it.second <= 0)
                    {
                        mini = it.first;
                        break;
                    }
                    else if(temp == 1)
                    {
                        mini = it.first;
                        break;
                    }  
                    
                    temp -= it.second;
                }
                ans.push_back(mini);
                
                if(mp.find(nums[i]) != mp.end())
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0)
                        mp.erase(nums[i]);
                }
                if(nums[j] < 0)
                {
                    mp[nums[j]]++;
                }
                
                i++;
                j++;
            }
        }
        
                int temp = x;
                int mini = 0;
                for(auto it : mp)
                {
                    if(temp - it.second <= 0)
                    {
                        mini = it.first;
                        break;
                    }
                    else if(temp == 1)
                    {
                        mini = it.first;
                        break;
                    } 
                    temp -= it.second;
                }
                
                ans.push_back(mini);
        
        return ans;
    }
};