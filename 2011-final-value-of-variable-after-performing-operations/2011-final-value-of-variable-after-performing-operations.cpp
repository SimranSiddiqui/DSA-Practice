class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int ans =0;
        string c;
        
        for(auto x : op)
        {
            istringstream s(x);
            while(s >> c)
            {
                s >> c;
                if(c[1] == '+')
                    ans++;
                else
                    ans--;
            }
        }
        
        return ans;
    }
};