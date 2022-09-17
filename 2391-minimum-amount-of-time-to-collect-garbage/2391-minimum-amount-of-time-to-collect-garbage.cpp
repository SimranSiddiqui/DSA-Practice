class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int n = travel.size();
        int sum =0;
        for(int i=0;i<n;i++)
        {
            sum += travel[i];
            travel[i] = sum;
        }
        
        sum =0;
        for(int i=0;i<garbage.size();i++)
        {
            sum += garbage[i].length();
        }
        
        int p=n, g=n, m=n;
        
        while(p>=0)
        {
            char s[] ="P";
            if(garbage[p].find(s) != -1 )
            {
                break;
            }
            else
                p--;
        }
        
         while(m>=0)
        {
             char s[] = "M";
            if(garbage[m].find(s) != -1)
            {
                break;
            }
            else
                m--;
        }
        
         while(g>=0)
        {
             char s[] = "G";
            if(garbage[g].find(s) != -1)
            {
                break;
            }
            else
                g--;
        }
        
        if(p>0)
            sum += travel[p-1];
        if(g>0)
            sum += travel[g-1];
        if(m>0)
            sum+=travel[m-1];
        
        return sum;
        
    }
};