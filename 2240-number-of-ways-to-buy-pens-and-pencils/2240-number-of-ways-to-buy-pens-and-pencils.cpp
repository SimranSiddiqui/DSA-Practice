class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans  = 0;
        
        for(int i=0;cost1*i<=total;i++)
        {
            int temp = total - cost1*i;
            int curr = floor(temp/cost2);
            ans += curr+1;
            
            //if(floor(temp/cost2) != ceil(temp/cost2))
              //  ans++;
        }
        
        return ans;
    }
};