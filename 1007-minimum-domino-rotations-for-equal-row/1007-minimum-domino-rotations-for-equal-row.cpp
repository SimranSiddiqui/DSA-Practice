class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int val1 = tops[0];
        int val2 = bottoms[0];
        
        int missT =0, missB =0, ans1 = INT_MAX, ans2 = INT_MAX;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            if(tops[i] != val1 && bottoms[i] != val1)
            {
                flag = true;
                break;
            }
            else if(tops[i] != val1)
            {
                missT++;
            }
            else if(bottoms[i] != val1)
            {
                missB++;
            }
        }
        
        if(!flag)
        {
            ans1 = min(missB, missT);
        }
        
        flag = false;
        missB =0, missT =0;
        for(int i=0;i<n;i++)
        {
            if(tops[i] != val2 && bottoms[i] != val2)
            {
                flag = true;
                break;
            }
            else if(tops[i] != val2)
            {
                missT++;
            }
            else if(bottoms[i] != val2)
            {
                missB++;
            }
        }
        
        if(!flag)
        {
            ans2 = min(missB, missT);
        }
        
        if(min(ans1, ans2) != INT_MAX)
            return min(ans1, ans2);
        return -1;
    }
};