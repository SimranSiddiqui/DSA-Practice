class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         unordered_set<string> seen;
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                int curr = board[i][j];
                if(curr == '.') continue;
                if(!seen.insert("row" + to_string(i) + "has" + to_string(curr)).second || 
                   !seen.insert("col" + to_string(j) + "has" + to_string(curr)).second ||
                   !seen.insert("box" + to_string(i/3) + to_string(j/3) + "has" + to_string(curr)).second
                ) {
                    return false;
                }
            }
        }
        return true;
    }
};