class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        unordered_map<string,vector<pair<string,string>>> mp;
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++)
        {
            int size = paths[i].size();
            int j =0;
            string root = "";
            while(paths[i][j] != ' ')
            {
                root += paths[i][j];
                j++;
            }
            j++;
            
            while(j<size)
            {
                 string num = "";
                 while(paths[i][j] != '.')
                 {
                   num += paths[i][j];
                    j++;
                 }
                
                j+=5;
                
                string text = "";
                while(j<size && paths[i][j] != ')')
                {
                    text += paths[i][j];
                    j++;
                }
                j+=2;
                
                if(mp.find(text) != mp.end())
                mp[text].push_back({root,num});
                else
                {
                    vector<pair<string,string>> vect(1,{root,num});
                    mp[text] = vect;   
                }
            }   
        }
        
        for(auto it: mp)
        {
            if(it.second.size()>1)
            {
                int v = it.second.size();
                vector<string> elem;
                
                for(int i=0;i<v;i++)
                {
                    string x = it.second[i].first + "/" + it.second[i].second + ".txt";
                    elem.push_back(x);
                }
                
                ans.push_back(elem);
            }
        }
        
        return ans;
    }
};