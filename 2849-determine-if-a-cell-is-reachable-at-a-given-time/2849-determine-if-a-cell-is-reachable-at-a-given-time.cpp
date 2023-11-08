class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dist = max(abs(sx-fx), abs(sy-fy));         
        
        if(dist == 0)
            return t!=1;          // Can't make extra moves
        else
            return dist <= t;
    }
};