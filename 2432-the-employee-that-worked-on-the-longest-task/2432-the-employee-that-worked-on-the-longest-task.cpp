class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        pair<int,int> longTask = make_pair(logs[0][1], logs[0][0]);
        int size = logs.size();
        
        for(int i=1;i<size;i++)
        {
            if(longTask.first < logs[i][1] - logs[i-1][1])
            {
                longTask.first = logs[i][1] - logs[i-1][1];
                longTask.second = logs[i][0];
            }
            else if(longTask.first == logs[i][1] - logs[i-1][1])
            {
                if(longTask.second > logs[i][0])
                {
                   longTask.first = logs[i][1] - logs[i-1][1];
                   longTask.second = logs[i][0]; 
                }
            }
        }
        
        return longTask.second;
    }
};