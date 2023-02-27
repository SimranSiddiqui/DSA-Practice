class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = jewels.length();
        int ans =0;
        
        for(int i=0;i<n;i++)
        {
            ans += count(stones.begin(), stones.end(), jewels[i]);
        }
        
        return ans;
    }
};