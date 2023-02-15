class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int carry =0;
        
        int i= n-1;
        while(i>=0 || k)
        {
          int sum =0;
          
            if(i>=0)
            {
                sum += num[i];
            }
            
            if(k)
            {
                int x = k%10;
                k/=10;
                sum += x;
            }
            
            sum += carry;
            
            if(i>=0)
            {
                num[i] = sum%10;
            }
            else
            {
                num.insert(num.begin(),sum%10);
            }
            
            carry = sum/10;
            i--;
        }
        
        if(carry)
        {
            num.insert(num.begin(),carry);
        }
        
        return num;
    }
};