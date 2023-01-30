class Solution {
public:
    int countDigits(int num) {
        int temp = num;
        int count = 0;
        
        while(temp)
        {
            int digi = temp%10;
            temp /= 10;
            
            if(num%digi == 0)
                count++;
        }
        
        return count;
    }
};