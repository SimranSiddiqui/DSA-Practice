class Solution {
public:
    int score(vector<int> &arr, int s, int e, int turn)
    {
        if(s <= e)
        {
            int chooseS = arr[s] - score(arr, s+1, e, -1*turn);
            int chooseE = arr[e] - score(arr, s, e-1, turn);
            
            return max(chooseS, chooseE);
        }
        
        return 0;
    }
    bool predictTheWinner(vector<int>& arr) {
        int n = arr.size();
        return score(arr, 0, n-1, 1) >= 0;
    }
};
