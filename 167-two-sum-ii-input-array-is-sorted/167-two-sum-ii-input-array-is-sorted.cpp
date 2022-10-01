class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i= 0;
        int j =n-1;
        
        vector<int> ans;
        
        while(i<j)
        {
            if(numbers[i] + numbers[j] == target)
            {
                ans = {i+1,j+1};
                break;
            }
            else if(numbers[i]+numbers[j] > target)
                j--;
            
            else
                i++;
        }
        
        return ans;
        
    }
};