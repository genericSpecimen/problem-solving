class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEOW;
    TrieNode() : children({}), isEOW(false) {}
};

class WordDictionary {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isEOW = true;
    }
    
    bool dfsSearch(string &word, int idx, TrieNode* root) {
        TrieNode* curr = root;
        
        for (int i=idx; i<word.size(); i++) {
            char ch = word[i];
            
            if (ch == '.') {
                // for each possible choice of character, start the search from the i+1 th char from child nodes
                for (auto it=curr->children.begin(); it != curr->children.end(); it++) {
                    if (dfsSearch(word, i+1, it->second)) return true;
                }
                return false;
            } else {
                if (curr->children.find(ch) == curr->children.end()) return false;
                curr = curr->children[ch];
            }
        }
        
        return curr->isEOW;        
    }
    
    bool search(string word) {
        return dfsSearch(word, 0, this->root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
