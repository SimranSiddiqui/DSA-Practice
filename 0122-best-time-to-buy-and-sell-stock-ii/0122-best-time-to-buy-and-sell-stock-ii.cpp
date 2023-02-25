class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currMin = prices[0];
        int profit = 0;
        
        for(int i=1;i<n;i++)
        {
            if(prices[i] > currMin)
            {
                profit += prices[i] - currMin;
                currMin = INT_MAX;
            }
            
            currMin = min(currMin, prices[i]);
        }
        
        if(profit == INT_MIN)
            return 0;
        return profit;
    }
};