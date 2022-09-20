class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        
        ans.push_back(words[0]);
        
        for(int i=1;i<n;i++)
        {
            string s2 = words[i];
                sort(s2.begin(),s2.end());
            string s1 = words[i-1];
                sort(s1.begin(),s1.end());
            if(s1 != s2)
            {
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};