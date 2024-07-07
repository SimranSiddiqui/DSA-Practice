class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int i = 0, j = 0;
        int curr = 0, space  = 0;
        vector<string> ans;
        
        while(j < n)
        {
            if(space+curr+words[j].length() <= maxWidth)
            {
                curr += words[j].length();
                
                if(curr+space < maxWidth)
                    space++;
                
                j++;
            }
            else
            {
                string x = "";
                space = maxWidth - curr;
                int a=0, b=0;
                
                if(j-i > 1){
                a = space/(j-i-1);
                b = space%(j-i-1);
                }
                else
                {
                    a = space;
                    b = 0;
                }
                cout << a;
                for(int ind=i;ind<j;ind++)
                {
                    x += words[ind];
                    
                    if(a == space && ind==i){
                        if(space > 0){
                        string t(space, ' ');
                        x += t;
                        }
                    }
                    else if(ind < j-1 && a>0)
                    {
                        string t(a, ' ');
                        x += t;
                        
                        if(b > 0)
                        {
                            x += ' ';
                            b--;
                        }
                    }
                }
                
                ans.push_back(x);
                
                i = j;
                space = 0;
                curr = 0;
                
            }
        }
        
                string x = "";
                space = maxWidth - curr;
                int a=0, b=0;
                
                if(j-i > 1){
                a = space/(j-i-1);
                b = space%(j-i-1);
                }
                else
                {
                    a = space;
                    b=0;
                }
                
                for(int ind=i;ind<j;ind++)
                {
                    x += words[ind];
                    if(ind != j-1)
                    {
                        x += ' ';
                        space--;
                    }
                }
        
        string vvv(space, ' ');
        x += vvv;
                
        ans.push_back(x);
        
        return ans;
    }
};