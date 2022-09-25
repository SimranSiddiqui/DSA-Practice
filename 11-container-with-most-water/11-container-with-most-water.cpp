class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxWater = 0;
        int i=0, j=n-1;
        int cArea=0;
        while(i<j)
        {
           cArea= (j-i)*min(height[i],height[j]);
            if(maxWater<cArea)
                maxWater=cArea;
            
            height[i]<height[j]?i++:j--;
        }
        return maxWater;
    }
};