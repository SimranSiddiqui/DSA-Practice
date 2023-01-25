class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);
        int m = trust.size();
        int townJudge = -1, count =0;

        for(int i=0;i<m;i++)
        {
            int a = trust[i][0];
            int b = trust[i][1];

            outdegree[a]++;
            indegree[b]++;
        }

        for(int i=1;i<n+1;i++)
        {
            if(outdegree[i] == 0 && indegree[i] == n-1)
            return i;
        }

        return -1;
    }
};