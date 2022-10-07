class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int ans =0;
        int currentBuyPrice = prices[0]; 
        
        for(int i=0;i<n;i++)
        {
            if(prices[i] > currentBuyPrice)
            {
                ans += prices[i] - currentBuyPrice;
                currentBuyPrice = prices[i];
            }
            else if(prices[i] < currentBuyPrice)
                currentBuyPrice = prices[i];
        }
        
        return ans;
    }
};