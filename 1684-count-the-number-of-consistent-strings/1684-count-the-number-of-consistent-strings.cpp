class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n= words.size();
        int count =0;
        
        for(int i=0;i<n;i++)
        {
            int m = words[i].size();
            int j =0;
            for(;j<m;j++)
            {
                if(allowed.find(words[i][j]) == -1 )
                    break;
            }
            
            if(j==m)
                count++;
        }
        return count;
    }
};