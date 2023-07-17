struct Node{
    Node* links[26];
    vector<string> st;
    
    bool contains(char c)
    {
        return (links[c - 'a'] != NULL);
    }
    
    void put(char c, Node* node)
    {
        links[c - 'a'] = node;
    }
    
    Node* get(char c)
    {
        return links[c - 'a'];
    }
    
};

class Solution {
private:
    Node* root;
    
public:
    
    Solution()
    {
        root = new Node();
    }
    
    void insert(string word)
    {
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->contains(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            
            if(node->st.size() < 3)
                node->st.emplace_back(word);
        }
    }
        
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        vector<vector<string>> ans(searchWord.length());
        sort(products.begin(), products.end());
        
        for(int i=0;i<n;i++)
        {
            insert(products[i]);
        }
        
        Node* node = root;
        for(int i=0;i<searchWord.length();i++)
        {
            vector<string> curr;
            
            if(!node->contains(searchWord[i]))
            {
                break;
            }
            node = node->get(searchWord[i]);
            
            ans[i] = node->st;
        }
        
        return ans;
    }
};