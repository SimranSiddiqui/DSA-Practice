class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        sort(piles.begin(), piles.end());
        
        for(int i=n-2;i>=n/3;i-=2)
        {
            sum += piles[i];
        }
        
        return sum;
    }
};