class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        
        int m=n+1;
        vector<int> color(m,-1);
        vector<vector<int>> adjl(m);
	
        for(auto i:dis){
            adjl[i[0]].push_back(i[1]);
            adjl[i[1]].push_back(i[0]);
        }
		
        queue<int> q;
        for(int x=1;x<=n;x++){
            
            if(color[x]==-1){
                q.push(x);
                color[x]=1;
                while(q.size()){
                    int node=q.front();
                    q.pop();
                    for(auto j:adjl[node]){
                        if(color[j]==-1){
                            color[j]=1-color[node];
                            q.push(j);
                        }
                        else if(color[j]==color[node]){
                            return false;
                        }
                        else continue;
                    }
                }
            }
        }
        
        return true;
        
    }
};