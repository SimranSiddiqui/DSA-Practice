class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end(), [&](int a, int b)
             {
                bool x = a < b;
                int digi1 = 0, digi2 = 0;
                while(a)
                {
                    if(a%2 != 0)
                    {
                        digi1++;
                    }
                    
                    a /= 2;
                }
                 while(b)
                {
                    if(b%2 != 0)
                    {
                        digi2++;
                    }
                    
                    b /= 2;
                }
                 
                if(digi1 != digi2)
                    return digi1 < digi2;
                else
                    return x;
             });
        
        return arr;
    }
};