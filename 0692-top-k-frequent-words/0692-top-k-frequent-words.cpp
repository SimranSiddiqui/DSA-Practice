class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
         map<string,int> mp;
        
        for(auto it :words){
            mp[it]++;
        }
        
        vector<string> ans;
         int check=INT_MIN;
       
        for(int i=0;i<k;i++)
            {
            for(auto it :mp){
                check = max(check,it.second);
            }
            
            for(auto it : mp){
                if(it.second == check){
                    ans.push_back(it.first);
                    mp.erase(it.first);
                    it.second = -1;
                    break;
                }
            }
            
             check=INT_MIN;
        }
        return ans;
    }
};