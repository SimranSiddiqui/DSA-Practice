class Solution {
public:
    int findFirst(int n)
    {
        string str = to_string(n);
        str[0] = '1';
        for(int i=1;i<str.length();i++)
        {
         str[i] = str[i-1] + 1;   
        }
        
        return stoi(str);
    }
    int digi(int n)
    {
        int count = 0;
        while(n)
        {
            count++;
            n /= 10;
        }
        return count;
    }
    int diff(int n)
    {
        int ret = 0;
        for(int i=0;i<n;i++)
        {
            ret += pow(10, i);
        }
        
        return ret;
    }
    vector<int> sequentialDigits(int low, int high) {
        int first = findFirst(low);
        vector<int> ans;
        
        if(first >= low && first <= high)
        ans.push_back(first);
        
        while(first <= high)
        {
            int lastDigi = first%10;
            if(lastDigi == 9)
            {
                first = findFirst(first*10);
                if(first >= low && first <= high)
                ans.push_back(first);
            }
            
            if(digi(first) == 9 && lastDigi == 9)
                break;
            int dig = digi(first);
            first += diff(dig);
            
            if(first >= low && first <= high)
                ans.push_back(first);
        }
        
        return ans;
    }
};