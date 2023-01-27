struct TrieNode {
    bool isWord;
    TrieNode *children[26];
    TrieNode() : isWord(false) {
        for(auto &a : children) a = nullptr;
    }
};

class Trie {
    public:
        TrieNode *root;

        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {
            TrieNode *node = root;
            for(auto &a : word) {
                int i = a - 'a';
                if(node->children[i] == nullptr) node->children[i] = new TrieNode();
                node = node->children[i];
            }
            
            node->isWord = true;
        }

        bool search(string word) {
            TrieNode *node = root;

            for(auto &a : word) {
                int i = a - 'a';
                if(node->children[i] == nullptr) return false;
                node = node->children[i];
            }

            return node->isWord;
        }
};

class Solution {
    public:
        Trie trie;

        bool dfs(string word, int index, int count) {
            TrieNode* cur = trie.root;

            for(int i = index; i < word.size(); i++) {
                if(cur->children[word[i] - 'a'] == nullptr) return false;
                cur = cur->children[word[i] - 'a'];

                if(cur->isWord) {
                    if(i == word.size() - 1) return count >= 1;
                    if(dfs(word, i + 1, count + 1)) return true;
                }
            }

            return false;
        }

        vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
            vector<string> res;
            trie = Trie();
            
            for(auto &word : words) trie.insert(word);
            for(auto &word : words) {
                if(word.size() == 0) continue;
                if(dfs(word, 0, 0)) res.push_back(word);
            }
            
            return res;
        }
};