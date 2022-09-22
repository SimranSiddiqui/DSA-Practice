class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,bool> mp;
        int n = rooms.size();
        queue<int> q;
        
        int m = rooms[0].size();
            for(int i=0;i<m;i++)
            {
                q.push(rooms[0][i]);
            }
            
            while(!q.empty())
            {
                int size = q.size();
                int mapSize = mp.size();
                for(int i=0;i<size;i++)
                {
                    int x = q.front();
                    q.pop();
                    if(mp.find(x) == mp.end() && x!=0)
                      mp[x] = true;
                    
                    int n = rooms[x].size();
                    for(int i=0;i<n;i++)
                    {
                        q.push(rooms[x][i]);
                    }
                }
                
                if(mapSize == mp.size())
                    break;
            }
        
       if(mp.size() >= n-1)
           return true;
        else
            return false;
        
    }
};