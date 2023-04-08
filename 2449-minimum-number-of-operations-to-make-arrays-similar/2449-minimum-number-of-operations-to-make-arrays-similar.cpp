class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long n = nums.size();
        
       vector<long long> evenNum, oddNum, evenTarget, oddTarget;
     
       for(long long i=0;i<n;i++)
       {
           if(nums[i] %2 ==0 )
               evenNum.push_back(nums[i]);
           else
               oddNum.push_back(nums[i]);
           
           if(target[i] % 2 == 0)
               evenTarget.push_back(target[i]);
           else
               oddTarget.push_back(target[i]);
       }
        
        sort(evenNum.begin(), evenNum.end());
        sort(oddNum.begin(), oddNum.end());
        sort(evenTarget.begin(), evenTarget.end());
        sort(oddTarget.begin(), oddTarget.end());
        
        long long plus=0, minus=0;
        for(long long i=0;i<evenNum.size();i++)
        {
            if(evenNum[i] - evenTarget[i] >= 0)
                plus += evenNum[i] - evenTarget[i];
            else
                minus += (evenNum[i] - evenTarget[i])*-1;
        }
        for(long long i =0 ;i<oddNum.size();i++)
        {
            if(oddNum[i] - oddTarget[i] >= 0)
                plus += oddNum[i] - oddTarget[i];
            else
                minus += (oddNum[i] - oddTarget[i])*-1;
        }
        
        
        return plus/2;
    }
};