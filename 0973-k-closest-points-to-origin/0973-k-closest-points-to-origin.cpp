class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        
        for(int i=0;i<n;i++)
        {
            int x = pow(points[i][0], 2) + pow(points[i][1], 2);
            pq.push(make_pair(x, make_pair(points[i][0] , points[i][1] )));
        }
        
        vector<vector<int>> ans;
        while(k--)
        {
            pair<int, pair<int, int>> x = pq.top();
            pq.pop();
            vector<int> curr;
            curr.push_back(x.second.first);
            curr.push_back(x.second.second);
            
            ans.push_back(curr);
        }
        
        return ans;
    }
};