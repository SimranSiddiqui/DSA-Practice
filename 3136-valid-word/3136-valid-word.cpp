class Solution {
public:
    bool isVowel(char c){
        return (c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u');
    }
    bool isValid(string word) {
        int n = word.length();
        bool alpha = 0, vow = 0, con = 0;
        
        for(int i=0;i<n&&n>=3;i++)
        {
            if(iswalnum(word[i])){
                alpha = 1;
                
                if(isVowel(tolower(word[i])))
                    vow = 1;
                else if(!isdigit(word[i]))
                    con = 1;
            }
            else
                return false;
        }
        
        return (alpha&&vow&&con);
    }
};