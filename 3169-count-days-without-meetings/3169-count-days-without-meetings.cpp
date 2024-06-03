class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        
        vector<vector<int>> olp;
        int start = meetings[0][0];
        int end = meetings[0][1];
        
        for(int i=0;i<n;i++)
        {
            while(i<n){
                if(meetings[i][0] <= end){
                    end = max(end, meetings[i][1]);
                    i++;
                }
                
                else{
                    olp.push_back({start, end});
                    start = meetings[i][0];
                    end = meetings[i][1];
                    break;
                }
            }
            
        }
        olp.push_back({start, end});
        
        int ans = 0, last = 0;
        for(int i=0;i<olp.size();i++){
            //cout << olp[i][0] << " " << olp[i][1] << "\n";
            ans += olp[i][0] - last - 1;
            last = olp[i][1];
        }
        ans += days-last;
        
        return ans;
    }
};