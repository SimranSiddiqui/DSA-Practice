class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>pairs(spells.size(),0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int start=0,end=potions.size()-1;
            while(start<=end){
                int mid=(start+end)/2;
                if((1ll*spells[i])*(1ll*potions[mid])<success) start=mid+1;
                else if((1ll*spells[i])*(1ll*potions[mid])>=success) end=mid-1; 
            }
            pairs[i]=potions.size()-start;
        }
        return pairs;
    }
};