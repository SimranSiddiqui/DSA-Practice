class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0], count =nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1] == 1)
            {
                sum += nums[i];
                count = sum;
            }
            else
            {
                break;
            }
        }
        
        sort(nums.begin(), nums.end());
        cout << count;
        for(int i=0;i<n;i++)
        {
            if(nums[i] < count)
                continue;
            else if(nums[i] > count)
                break;
            else if(i>0 && nums[i] == nums[i-1])
                continue;
            else
                count++;
        }
        
        return count;
    }
};