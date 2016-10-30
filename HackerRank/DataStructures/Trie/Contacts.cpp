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
    int cnt;
    trieNode() {
        cnt = 0;
    }
};

void trie_insert(trieNode *root, string &s) {
    trieNode* temp = root;
    for (int level = 0; level < s.size(); ++level) {
        if(!temp->children[s[level]]) {
            temp->children[s[level]] = new trieNode();
        }
        temp = temp->children[s[level]];
        temp->cnt++;
    }
}

int trie_search(trieNode *root, string &s) {
    trieNode* temp = root;
    for (int level = 0; level < s.size(); ++level) {
        if(!temp->children[s[level]])
            return 0;
        temp = temp->children[s[level]];
    }
    if (temp != NULL)
        return temp->cnt;
    else
        return 0;
}

//https://www.hackerrank.com/challenges/contacts

int main() {
//    Boost;
    trieNode* root = new trieNode();
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string a,s;
        cin>>a>>s;
        if(a == "add")
            trie_insert(root,s);
        else
            cout<<trie_search(root , s)<<"\n";
    }
    return 0;
}