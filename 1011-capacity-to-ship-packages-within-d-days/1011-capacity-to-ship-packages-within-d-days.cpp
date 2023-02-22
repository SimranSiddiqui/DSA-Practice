class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high =0, mid =0;
        int n = weights.size();
        
        for(int i=0;i<n;i++)
        {
            high += weights[i];
            low = max(low, weights[i]);
        }
        
        
        while(low < high)
        {
            mid = (high+low)/2;
            int curr =0, day = 1;
            
            for(int i=0;i<n;i++)
            {
                 curr += weights[i];
               
                 if(curr > mid)
                 {
                     day++;
                     curr = weights[i];
                 }
            }
            
            
            if(day <= days)
                high = mid;
            else
                low = mid+1;
            
        }
        
        return low;
    }
};