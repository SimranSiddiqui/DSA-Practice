class Solution {
public:
    int largestInteger(int num) {
        vector<int> odd;
        vector<int> even;
        vector<bool> parity; 
        string s = to_string(num);
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            if((s[i] - '0')%2 == 0)
            {
                even.push_back(s[i]-'0');
                parity.push_back(0);
            }
            else
            {
                odd.push_back(s[i] - '0');
                parity.push_back(1);
            }
        }
        
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        
        int i =0, j=0;
        s = "";
        for(int k=0;k<n;k++)
        {
            if(parity[k])
            {
                s  += to_string(odd[i]);
                i++;
            }
            else
            {
                 s  += to_string(even[j]);
                 j++;
            }
        }
        
        return stoi(s);
        
    }
};