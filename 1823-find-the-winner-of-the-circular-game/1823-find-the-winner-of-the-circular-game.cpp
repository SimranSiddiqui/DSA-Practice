class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> frenz;
        for(int i=1;i<=n;i++)
        {
            frenz.push_back(i);
        }
        
        int i = 0;
        while(frenz.size() > 1)
        {
            i = (i+k-1)%n;
            frenz.erase(frenz.begin() + i);
            n--;
        }
        
        return frenz[0];
    }
};