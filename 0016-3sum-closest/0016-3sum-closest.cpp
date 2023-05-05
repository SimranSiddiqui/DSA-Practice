class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int left = INT_MIN;
        int right = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int l = i+1, r = n-1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target)
                    return target;
                else if(sum > target)
                {
                    right = min(right, sum);
                    r--;
                }
                else 
                {
                    left = max(left, sum);
                    l++;
                }
            }
        }
        
        if(abs(left-target) < abs(right-target) && left != INT_MIN)
            return left;
        else
            return right;
    }
};