class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digiLog, letLog;
        int n = logs.size();
        
        unordered_map<string, vector<string>> mp;
        
        for(int i=0;i<n;i++)
        {
            string curr = logs[i];
            int len = curr.length();
            int j =0;
            string id = "";
            while(curr[j] != ' ')
            {
                id += curr[j];
                j++;
            }
            j++;
            
            if(isdigit(curr[j]))
                digiLog.push_back(curr);
            else
            {
                mp[curr.substr(j, len-j)].push_back(id);
                letLog.push_back(curr.substr(j, len-j));
            }
            
        }
        
        sort(letLog.begin(), letLog.end());
        for(int i=0,ind=0;i<letLog.size();i++)
        {
            int count = mp[letLog[i]].size();
            
            if(i > 0 && letLog[i] == letLog[i-1])
                continue;
            
            vector<string> temp = mp[letLog[i]];
            sort(temp.begin(), temp.end());
                
            for(int j=0;j<count;j++,ind++)
            {
                string x = temp[j];
                x += " ";
                x += letLog[i];
                
                logs[ind] = x;
            }
        }
        
        for(int i=0;i<digiLog.size();i++)
        {
          logs[letLog.size()+i] = digiLog[i];   
        }
        
        return logs;
    }
};