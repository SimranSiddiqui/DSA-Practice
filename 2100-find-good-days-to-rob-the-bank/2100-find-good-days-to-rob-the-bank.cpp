class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> left, right(n, 0);
        vector<int> ans; 
        
        int streak = 0;
        for(int i=0;i<n;i++)
        {
            if(i>0 && security[i] <= security[i-1])
                streak++;
            else
                streak = 0;
            
            left.push_back(streak);
        }
        
        for(int i=n-1, streak=0;i>=0;i--)
        {
            if(i<n-1 && security[i] <= security[i+1])
                streak++;
            else
                streak = 0;
            
            right[i] = streak;
        }
        
        for(int i=0;i<n;i++)
        {
            cout << left[i] << " "<< right[i] << endl;
            if(left[i]>=time && right[i] >= time)
                ans.push_back(i);
        }
        
        return ans;
    }
};