/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n) == 0)
            return n;
        
       long i =1, j=n, mid =0;
        while(i<=j)
        {
            mid = (i+j)/2;
            if(guess(mid) == -1)
            {
                j = mid-1;
            }
            else if(guess(mid) == 1)
            {
                i = mid+1;
            }
            else 
                return mid;
        }
      
        return mid;
    }
};