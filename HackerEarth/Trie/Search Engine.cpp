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
    int weight;
    bool isLeaf;
    trieNode() {
        isLeaf = false;
        weight = 0;
    }
};

void trie_insert(trieNode *root, string &s,int wt) {
    trieNode* temp = root;
    for (int level = 0; level < s.size(); ++level) {
        if(!temp->children[s[level]]) {
            temp->children[s[level]] = new trieNode();
        }
        if(wt > temp->weight)
            temp->weight = wt;
        temp = temp->children[s[level]];
    }
    temp->isLeaf = true;
}

int trie_search(trieNode *root, string &s) {
    trieNode* temp = root;
    for (int level = 0; level < s.size(); ++level) {
        if(!temp->children[s[level]])
            return -1;
        temp = temp->children[s[level]];
    }
    if (temp != NULL)
        return temp->weight;
    else
        return -1;
}

//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/

int main() {
//    Boost;
    trieNode* root = new trieNode();
    int n,q;
    cin>>n>>q;
    for (int i = 0; i < n; ++i) {
        int a;
        string s;
        cin>>s>>a;
        trie_insert(root,s,a);
    }
    for (int i = 0; i < q; ++i) {
        string s;
        cin>>s;
        cout<<trie_search(root,s)<<"\n";
    }
    return 0;
}