class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int count = 0;
        vector<int> ans;
        
        for(int i=left;i<=right;i++)
        {
            int temp = i;
            while(temp)
            {
                int digi = temp%10;
                if(digi==0 || i%digi)
                    break;
                
                temp /= 10;
            }
            
            if(!temp && i!=0)
                ans.push_back(i);
                
        }
        
        return ans;
    }
};