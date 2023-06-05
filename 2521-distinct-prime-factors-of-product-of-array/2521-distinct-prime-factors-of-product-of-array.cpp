class Solution {
    
    bool check(int i)
    {
        if(i == 1)
            return false;
        if(i == 2)
            return true;
        
        for(int j=2;j*j<=i;j++)
        {
            if(i%j == 0)
                return false;
        }
        
        return true;
    }
    
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        
        vector<int> primes;
        for(int i=1;i<1000;i++)
        {
            if(check(i))
                primes.push_back(i);
        }
        
        for(int i=0;i<n;i++)
        {
            int num = nums[i];
            for(int j=0;j<primes.size();j++)
            {
                while(num && num%primes[j]==0)
                {
                  //  cout << num << " ";
                    num /= primes[j];
                    st.insert(primes[j]);
                }
            }
        }
        
        return st.size();
    }
};