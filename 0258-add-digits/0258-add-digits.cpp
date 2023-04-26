class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
       do
       {
           sum = 0;
           int temp = num;
           while(temp != 0)
           {
             sum += temp%10;
             temp = temp/10;
           }
           num = sum ;
        } while(num/10 != 0);
        return sum;
    }
};