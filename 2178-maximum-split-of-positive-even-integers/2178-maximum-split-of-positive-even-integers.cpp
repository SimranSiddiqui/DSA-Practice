class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        long long sum =0;
        
        if(finalSum % 2 )
            return {};
        
        int i = 2;
        unordered_map<long long, int> mp;
        while(sum < finalSum)
        {
            if(sum+i > finalSum)
            {
                break;
            }
            sum += i;
            mp[i]++;
            i += 2;
        }
        
        //cout << i << " " << sum;
        if(sum != finalSum)
        {
            sum += i;
            mp[i]++;
            mp.erase(sum - finalSum);
        }
        
        vector<long long > ans;
        for(auto it : mp)
        {
            ans.push_back(it.first);
        }
        
        return ans;
    }
};