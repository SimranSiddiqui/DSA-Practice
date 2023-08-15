class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        stable_sort(nums.begin(), nums.end(), [&](auto a, auto b){
            return (a==pivot && b>pivot) || (a<pivot && b==pivot) || (a<pivot && b>pivot);
        });
        
        return nums;
    }
};