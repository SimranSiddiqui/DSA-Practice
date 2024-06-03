class Compare {
public:
    bool operator()(pair<char, int> below, pair<char, int> above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
 
        return false;
    }
};
class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        
        for(int i=0;i<n;i++)
        {
            if(s[i] != '*'){
                pq.push({s[i], i});
            }
            else{
                pair<char, int> t = pq.top();
                pq.pop();
                
                s[t.second] = '.';
            }
        }
        
        string ans = "";
        for(auto it : s){
            if(it != '.' && it != '*')
                ans += it;
        }
        
        return ans;
    }
};