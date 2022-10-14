class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        int n1 = ransomNote.size();
        int n2 = magazine.size();
        
        for(int i=0;i<n2;i++)
        {
            mp[magazine[i]]++;
        }
        
        for(int i=0;i<n1;i++)
        {
            if(mp.find(ransomNote[i])==mp.end() || mp[ransomNote[i]] <= 0)
                return false;
            else
                mp[ransomNote[i]]--;
        }
        
        return true;
        
    }
};