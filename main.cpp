#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define FastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define present(m,v) (m.find(v)!=m.end())
#define all(x) begin(x), end(x)

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

typedef unsigned char byte;

class SuffixNode {
public:
    int depth, begin, end;
    SuffixNode **children;
    SuffixNode *parent, *suffixLink;

    SuffixNode(int begin, int end, int depth, SuffixNode *parent) {
        children = new SuffixNode *[28];
        this->begin = begin;
        this->end = end;
        this->parent = parent;
        this->depth = depth;
    }

    bool contains(int d) {
        return depth <= d && d < depth + (end - begin);
    }
};

string alphabet;
int alphabetSize;
int lcsLength;
int lcsBeginIndex;

class SuffixTree {
public:
    SuffixNode *buildSuffixTree(string s) {
        int n = s.length();
        int *a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = alphabet.find(s.at(i));
        }
        SuffixNode *root = new SuffixNode(0, 0, 0, NULL);
        SuffixNode *cn = root;
        root->suffixLink = root;
        SuffixNode *needsSuffixLink = NULL;
        int lastRule = 0;
        int j = 0;
        for (int i = -1; i < n - 1; i++) {
            int cur = a[i + 1];
            for (; j <= i + 1; j++) {
                int curDepth = i + 1 - j;
                if (lastRule != 3) {
                    if (cn->suffixLink != NULL)
                        cn = cn->suffixLink;
                    else
                        cn = cn->parent->suffixLink;
                    int k = j + cn->depth;
                    while (curDepth > 0 && !cn->contains(curDepth - 1)) {
                        k += cn->end - cn->begin;
                        cn = cn->children[a[k]];
                    }
                }
                if (!cn->contains(curDepth)) {
                    if (needsSuffixLink != NULL) {
                        needsSuffixLink->suffixLink = cn;
                        needsSuffixLink = NULL;
                    }
                    if (cn->children[cur] == NULL) {
                        cn->children[cur] = new SuffixNode(i + 1, n, curDepth, cn);
                        lastRule = 2;
                    } else {
                        cn = cn->children[cur];
                        lastRule = 3;
                        break;
                    }
                } else {
                    int end = cn->begin + curDepth - cn->depth;
                    if (a[end] != cur) {
                        SuffixNode *newn = new SuffixNode(cn->begin, end, cn->depth, cn->parent);
                        newn->children[cur] = new SuffixNode(i + 1, n, curDepth, newn);
                        newn->children[a[end]] = cn;
                        cn->parent->children[a[cn->begin]] = newn;
                        if (needsSuffixLink != NULL)
                            needsSuffixLink->suffixLink = newn;
                        cn->begin = end;
                        cn->depth = curDepth;
                        cn->parent = newn;
                        cn = needsSuffixLink = newn;
                        lastRule = 2;
                    } else if (cn->end != n || (cn->begin - cn->depth) < j) {
                        lastRule = 3;
                        break;
                    } else
                        lastRule = 1;
                }
            }
        }
        root->suffixLink = NULL;
        return root;
    }

    /*
     * Funtion to find longest common substring
     */
    int findLCS(SuffixNode *node, int i1, int i2) {
        if (node->begin <= i1 && i1 < node->end)
            return 1;
        if (node->begin <= i2 && i2 < node->end)
            return 2;
        int mask = 0;
        for (int f = 0; f < alphabetSize; f++) {
            if (node->children[f] != NULL) {
                mask |= findLCS(node->children[f], i1, i2);
            }
        }
        if (mask == 3) {
            int curLength = node->depth + node->end - node->begin;
            if (lcsLength < curLength) {
                lcsLength = curLength;
                lcsBeginIndex = node->begin;
            }
        }
        return mask;
    }

    /*
     * Funtion to find longest common substring
     */
    void findLCS(string s1, string s2) {
        string x = "-";
        string y = "#";
        string ns1 = s1;
        string ns2 = s2;
        string s = s1.append(x.append(s2.append(y)));
        SuffixNode *root = buildSuffixTree(s);
        lcsLength = 0;
        lcsBeginIndex = 0;
        findLCS(root, ns1.length(), ns1.length() + ns2.length() + 1);
        bool chk = lcsLength > 0;
        if (chk) {
            cout << lcsLength;
            cout << endl;
        } else {
            cout << "No substring found" << endl;
        }
    }
};

int main() {
    FastIO;
    alphabet = "abcdefghijklmnopqrstuvwxyz-#";
    alphabetSize = alphabet.length();
    string s1,s2;
    cin>>s1;
    cin>>s2;
    SuffixTree st;
    st.findLCS(s1, s2);
    return 0;
}