class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        map<int, int, greater<int>> mp;

        for(int i=0,j=0;j<n;)
        {
            if(j-i < k)
            {
                mp[nums[j]]++;
                j++;
            }
            else
            {
                ans.push_back(mp.begin()->first);
                mp[nums[j]]++;

                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                mp.erase(nums[i]);

                i++;
                j++;
            }
        }

        ans.push_back(mp.begin()->first);

        return ans;
    }
};