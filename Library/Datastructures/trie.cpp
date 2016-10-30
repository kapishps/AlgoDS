#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

struct trieNode {
    unordered_map<char, trieNode*> children;
    bool isLeaf;
    trieNode() {
        isLeaf = false;
    }
};

void trie_insert(trieNode *root, string &s) {
    trieNode* temp = root;
    for (int level = 0; level < s.size(); ++level) {
        if(!temp->children[s[level]]) {
            temp->children[s[level]] = new trieNode();
        }
        temp = temp->children[s[level]];
    }
    temp->isLeaf = true;
}

bool trie_search(trieNode *root, string &s) {
    trieNode* temp = root;
    for (int level = 0; level < s.size(); ++level) {
        if(!temp->children[s[level]])
            return 0;
        temp = temp->children[s[level]];
    }
    return (temp != NULL && temp->isLeaf);
}

int main() {
//    Boost;
    trieNode* root = new trieNode();
    string s[8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    for (int i = 0; i < 8; ++i) {
        trie_insert(root , s[i]);
    }
    string output[2] = {"Not present in trie", "Present in trie"};
    string to_find[4] = {"the", "these", "their", "thaw"};
    for (int i = 0; i < 4; ++i) {
        cout<<to_find[i]<<" --- "<<output[trie_search(root, to_find[i])]<<"\n";
    }
    return 0;
}