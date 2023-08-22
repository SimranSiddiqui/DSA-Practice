class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        int ans= 0;
        
        for(int i=n-1;i>=0;i--){
            ans += pow(26, n-i-1)*(columnTitle[i]-'A'+1);
        }
        
        return ans;
    }
};