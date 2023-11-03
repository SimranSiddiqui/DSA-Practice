class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int num = 1;
        int i = 0;
        int len = target.size();
        vector<string> ans;
        
        while(i<len)
        {
            int curr = target[i];
            
            while(curr > num)
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                num++;
            }
            
            ans.push_back("Push");
            i++;
            num++;
        }
        
        return ans;
    }
};