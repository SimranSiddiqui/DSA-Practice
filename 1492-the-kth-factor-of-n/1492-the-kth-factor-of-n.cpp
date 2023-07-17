class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> fact;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                fact.push_back(i);   
                
                if(n/i != i)
                    fact.push_back(n/i);
            }
        }
        
        sort(fact.begin(), fact.end());
        int ans =-1;
     
        if(k<=fact.size())
        {
            ans = fact[k-1];
        } 
        
        return ans;
    }
};