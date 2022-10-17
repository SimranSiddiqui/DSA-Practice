class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool arr[26];
        for(int i=0;i<26;i++)
        {
            arr[i] = false;
        }
        
        int n = sentence.length();
        for(int i=0;i<n;i++)
        {
            if(!arr[sentence[i] - 'a'])
                arr[sentence[i]-'a'] = true;
        }
        
        for(int i=0;i<26;i++)
        {
            if(!arr[i])
                return false;
        }
        
        return true;
    }
};