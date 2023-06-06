class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n = nums.size();
        int m = l.size();
        
        for(int i=0;i<m;i++)
        {
            int left = l[i];
            int right = r[i];
            
            /*if(right - left < 1)
            {
                ans.push_back(true);
                continue;
            }*/
            
            vector<int> curr(nums.begin()+left, nums.begin()+right+1);
            sort(curr.begin(), curr.end());
            int diff = curr[0] - curr[1];
            
            bool flag = false;
            for(int j=1;j<curr.size()-1;j++)
            {
                if(curr[j] - curr[j+1] != diff)
                {
                    flag = true;
                    ans.push_back(false);
                    break;
                }
            }
            
            if(!flag)
            ans.push_back(true);
        }
        
        return ans;
    }
};