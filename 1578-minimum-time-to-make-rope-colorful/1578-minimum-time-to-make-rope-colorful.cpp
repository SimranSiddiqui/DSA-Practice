class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        
        int ans =0;
        int currentMax = neededTime[0];
        int count =1;
        int sum = neededTime[0];
        
        for(int i=1;i<n;i++)
        {
            while(colors[i] == colors[i-1])
            {
                count++;
                sum += neededTime[i];
                currentMax = max(currentMax,neededTime[i]);
                i++;
            }
            
            if(count>1)
            ans += (sum - currentMax);
            
            if(i<n)
            {
                currentMax = neededTime[i];
                sum = neededTime[i];
            }
            count =1;
            
        }
        
        return ans;
    }
};