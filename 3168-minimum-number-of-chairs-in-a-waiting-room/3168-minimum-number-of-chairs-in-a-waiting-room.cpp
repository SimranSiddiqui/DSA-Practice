class Solution {
public:
    int minimumChairs(string s) {
        int n = s.length();
        int len = 0, ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            if(s[i] == 'E'){
                len++;
                ans = max(ans, len);
            }
            else
                len--;
        }
        
        return ans;
    }
};