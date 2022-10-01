class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int ans = 0;
        
        
        for(int i=0;i<n-1;)
        {
            int j =i+1;
            while(timeSeries[j] == timeSeries[j-1])
            {
                j++;
            }
            
           if(timeSeries[j] - timeSeries[i] >= duration)
           {
               ans += duration;
           }
           else 
           {
               ans += timeSeries[j] - timeSeries[i];
           }
            
            i =j;
        }
        return ans+duration;
    }
};