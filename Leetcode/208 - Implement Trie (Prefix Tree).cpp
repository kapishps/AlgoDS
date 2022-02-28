class Trie {
public:
    struct trieNode {
        unordered_map<char, trieNode*> children;
        bool isleaf;
        trieNode(){
            isleaf = false;
        }
    };
    
    trieNode *root;
    
    Trie() {
        root = new trieNode();
    }
    
    void insert(string word) {
        trieNode *temp = root;
        for(int i =0; i<word.size(); i++){
            if(!temp->children[word[i]]){
                temp->children[word[i]] = new trieNode();
            }
            temp = temp->children[word[i]];
        }
        temp->isleaf = true;
    }
    
    bool search(string word) {
        trieNode *temp = root;
        for(int i =0; i<word.size(); i++){
            if(!temp->children[word[i]]){
                return false;
            }
            temp = temp->children[word[i]];
            
        }
        return temp->isleaf;
    }
    
    bool startsWith(string prefix) {
        trieNode *temp = root;
        for(int i =0; i<prefix.size(); i++){
            if(!temp->children[prefix[i]]){
                return false;
            }
            temp = temp->children[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */