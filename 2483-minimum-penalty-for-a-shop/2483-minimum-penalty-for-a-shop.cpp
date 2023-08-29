class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> left, right(n+1);
        int ans = INT_MAX, idx=0;
       
        for(int i=0,sum = 0;i<=n;i++)
        {
            left.push_back(sum);
            if(i<n && customers[i] == 'N')
                sum++;
        }
        
        for(int i=n,sum=0;i>=0;i--)
        {
            if(i<n && customers[i] == 'Y')
                sum++;
            
            right[i] = sum;
        }
        
        for(int i=0;i<=n;i++)
        {
            if(right[i] + left[i] < ans)
            {
                ans = right[i] + left[i];
                idx = i;
            }
        }
        
        return idx;
    }
};