class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        sort(salary.begin(),salary.end());
        double sum = 0.0000;
        for(int i=1;i<n-1;i++)
        {
            sum += salary[i];
        }
        
        return sum/(n-2);
    }
};