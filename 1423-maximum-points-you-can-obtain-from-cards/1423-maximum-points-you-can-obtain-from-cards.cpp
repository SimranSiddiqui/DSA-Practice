class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int sum =0, ans=INT_MIN;
        for(int i=0,j=n-1;i<n && i>=0;)
        {
            if(i < k && j == n-1)
            {
                sum += cardPoints[i];
                ans = max(ans, sum);
                i++;
            }
            else if(i > 0)
            {
                sum += cardPoints[j];
                sum -= cardPoints[i-1];
                ans = max(ans, sum);
                
                j--;
                i--;
            }
            else
                break;
        }
        
        return ans;
    }
};