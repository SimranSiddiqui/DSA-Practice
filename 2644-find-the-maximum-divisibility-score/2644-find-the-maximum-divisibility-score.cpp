class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        vector<int> scores;
        int n = nums.size();
        int m = divisors.size();
        
        sort(divisors.begin(), divisors.end(), greater<int>());
        for(int i=0;i<m;i++)
        {
            int count =0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]%divisors[i] == 0)
                    count++;
            }
            
            scores.push_back(count);
        }
        
        int ans = INT_MIN;
        int index = 0;
        for(int i=0;i<scores.size();i++)
        {
            if(scores[i] >= ans)
            {
                ans = scores[i];
                index = i;
            }
        }
        
        return divisors[index];
    }
};