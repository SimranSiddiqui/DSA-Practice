class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp;
        int count = 0;
        int ans = INT_MIN;
        
        int i=0, j=0;
        while(j<2 && j<n)
        {
            count++;
            ans = max(ans, count);
            mp[fruits[j]]++;
            j++;
        }
        
        while(j<n)
        {
            if(mp.size() < 2 || mp.find(fruits[j]) != mp.end())
            {
                mp[fruits[j]]++;
                count++; 
                ans = max(ans, count);
                j++;
            }
            else
            {
                while(mp.size() >= 2)
                {
                    mp[fruits[i]]--;
                    count--;
                    if(mp[fruits[i]] == 0)
                    {
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                
                mp[fruits[j]]++;
                count++;
                ans = max(ans, count);
                j++;
            }
        }
        
        return ans;
    }
};