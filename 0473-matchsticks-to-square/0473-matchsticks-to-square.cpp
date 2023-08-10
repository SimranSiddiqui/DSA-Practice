class Solution {
    bool dfs(int i, vector<int> &ms, int side, vector<int> &v, int n) {
        if(i == n) {
            return v[0] == v[1] && v[1] == v[2] && v[2] == v[3];
        }
        for(int k=0; k<4; k++) {
            if(v[k] + ms[i] > side) continue;
            v[k] += ms[i];
            if(dfs(i + 1, ms, side, v, n)) return true;
            v[k] -= ms[i];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& ms) {
        int s = accumulate(ms.begin(), ms.end(), 0), n = ms.size();
        if(s % 4) return false;
        sort(ms.begin(), ms.end(), greater<int>());
        int side = s / 4;
        vector<int> v(4);
        return dfs(0, ms, side, v, n);
    }
};