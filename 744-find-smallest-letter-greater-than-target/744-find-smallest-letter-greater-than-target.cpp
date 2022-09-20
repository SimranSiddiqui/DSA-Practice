class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        char ans;
        
        for(int i=0;i<n;i++)
        {
            if(letters[i] > target)
            {
                ans = letters[i];
                return ans;
            }
        }
        
        return letters[0];
        
    }
};