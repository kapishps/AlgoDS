#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <stack>

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/*----------------------- List Cycle --------------------------*/
ListNode* detectCycle(ListNode* root) {
    ListNode *p1 = root, *p2 = root;
    int flag = 0;
    while (p1 && p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        p1 = root;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
    return NULL;
}

int main() {
    Boost;

    return 0;
}
