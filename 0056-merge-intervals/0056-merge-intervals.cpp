class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<n;i++)
        {
            while(i < n)
            {
                if(end < intervals[i][0])
                {
                    ans.push_back({start, end});
                    start = intervals[i][0];
                    end = intervals[i][1];
                    break;
                }
                else if(intervals[i][0] <= end)
                {
                    if(end < intervals[i][1])
                        end = intervals[i][1];
                }
                
                i++;
            }
        }
        
        ans.push_back({start, end});
        return ans;
    }
};