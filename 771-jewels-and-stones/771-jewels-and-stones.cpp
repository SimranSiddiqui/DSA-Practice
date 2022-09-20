class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = stones.size();
        int ans =0;
        
        for(int i=0;i<n;i++)
        {
            if(jewels.find(stones[i]) != -1)
                ans++;
        }
        
        return ans;
    }
};