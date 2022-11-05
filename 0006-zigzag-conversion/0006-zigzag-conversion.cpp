class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        vector<vector<char>> mat;
        
        int n = s.length();
        int i =0;
        int j =0;
        while(i<n)
        {
          vector<char> x(numRows, ' ');
            if(j%(numRows-1) == 0)
            {
                for(int k=0;k<numRows && i<n;k++)
                {
                   x[k] = s[i];
                    i++;
                }
                j++;
                mat.push_back(x);
            }
            else 
            {
              for(int k=numRows-2;k!=0 && i<n; i++,k--,j++)
              {
                  vector<char> x(numRows, ' ');
                  x[k] = s[i];
                  mat.push_back(x);
              }
            }     
        }
        
        string ans = "";
            for(int i=0;i<mat[0].size();i++)
            {
                for(int j=0;j<mat.size();j++)
                {
                   if(mat[j][i] != ' ')
                       ans += mat[j][i];
                }
            }
        
        return ans;
    }
};