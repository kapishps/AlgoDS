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

bool trie_insert(trieNode *root, string &s) {
    trieNode* temp = root;
    int cnt=0;
    for (int level = 0; level < s.size(); ++level) {
        if(!temp->children[s[level]]) {
            temp->children[s[level]] = new trieNode();
            cnt++;
        }
        if(temp->isLeaf)
            return 0;
        temp = temp->children[s[level]];
    }
    if(cnt==0)
        return 0;
    temp->isLeaf = true;
    return 1;
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

//https://www.hackerrank.com/challenges/no-prefix-set

int main() {
//    Boost;
    trieNode* root = new trieNode();
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        if(!trie_insert(root,s)){
            cout<<"BAD SET"<<"\n";
            cout<<s;
            return 0;
        }
    }
    cout<<"GOOD SET";
    return 0;
}