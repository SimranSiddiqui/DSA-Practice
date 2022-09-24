class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> alpha;
        
        char c = 'a';
        for(int i=0;alpha.size()<26;i++)
        {
            if(key[i] == ' ')
                continue;
            if(alpha.find(key[i]) == alpha.end())
            {
                alpha[key[i]] = c;
                c++;
            }
        }
        
        int n= message.length();
        
        for(int i=0;i<n;i++)
        {
            if(message[i] == ' ')
                continue;
            else
            {
                message[i] = alpha[message[i]];
            }
        }
        
        return message;
    }
};