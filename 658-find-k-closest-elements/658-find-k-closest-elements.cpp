class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        
        int index = -1;
        bool find = false;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
            {
                find = true;
                index =i;
                ans.push_back(arr[i]);
                k--;
                break;
            }
            else if(arr[i] > x)
            {
                index =i;
                break;
            }
        }
        
        if(index==-1 && arr[0]>x)
        {
            index = 0;
           while(k-- && index<n)
           {
               ans.push_back(arr[index]);
               index++;
           }
        }
        else if( index == -1)
        {
            index =n-1;
            while(k-- && index>=0)
            {
                ans.push_back(arr[index]);
                index--;
            }
        }
        else
        {
            int i,j;
            if(!find)
            {
                 i = index-1;
                 j = index;
            }
            else
            {
                i = index-1;
                j = index+1;
            }
            
            while(k--)
            {
                if(i<0 && j>=n)
                {
                    break;
                }
                else if(i<0)
                {
                    ans.push_back(arr[j]);
                    j++;
                }
                else if(j>=n)
                {
                    ans.push_back(arr[i]);
                    i--;
                }
                else if(abs(x-arr[i]) <= abs(x-arr[j]))
                {
                    ans.push_back(arr[i]);
                    i--;
                }
                else
                {
                    ans.push_back(arr[j]);
                    j++;
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};