#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

class InputData {
public:
    int timestamp;
    pair<int, int> handShakePair;
    friend ostream &operator << ( ostream &out, const InputData data ) {
        out << "Timestamp " << data.timestamp << "Pair (" << data.handShakePair.first
            <<"  "<< data.handShakePair.second << ")\n";
        return out;
    }
    InputData( int _timestamp, pair<int, int> _pair ) {
        timestamp = _timestamp;
        handShakePair = _pair;
    }
    ~InputData(){}
};

class HandShake {
private:
    vector< InputData > inputs;
    int M;
    int N;
    int minimumTime;
public:
    int getMinimumTime() {
        return minimumTime;
    }
    void minimumTimeIs( int _minimumTime ) {
        minimumTime = _minimumTime;
    }
    void parseInput();
    void minimumTimeToKnowEachOther();
    HandShake() {
        M = 0;
        N = 0;
        minimumTime = 0;
    }
    ~HandShake(){}
};

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 9;

int parent[MAXN], rnk[MAXN];

int findset(int x) {
    if (x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void unionset(int x, int y) {
    int px = findset(x), py = findset(y);
    if (px != py) {
        if (rnk[px] > rnk[py]) {
            parent[py] = px;
            rnk[px] += rnk[py];
        } else {
            parent[px] = py;
            rnk[py] += rnk[px];
        }
    }
}

void initialiseset(int start, int end) {
    for (int i = start; i <= end; ++i) {
        parent[i] = i;
        rnk[i] = 1;
    }
}

void HandShake::minimumTimeToKnowEachOther()
{
    // Write your CODE here
    // Set the minimumTime using minimumTimeIs( <> ) function
    initialiseset(0,N);
    for (int i = 0; i < inputs.size(); i++) {
        unionset(inputs[i].handShakePair.first, inputs[i].handShakePair.second);
        if (rnk[findset(inputs[i].handShakePair.first)] == N) {
            minimumTimeIs(inputs[i].timestamp);
            break;
        }
    }
}

void HandShake::parseInput() {
    int timestamp = 0;
    int person1 = 0;
    int person2 = 0;

    cin >> M >> N;
    cout << "Value of M " << M <<  "N " << N << "\n";
    for ( int i = 0; i < M; ++i ) {
        cin >> timestamp >> person1 >> person2;
        inputs.push_back(InputData( timestamp, make_pair( person1, person2 ) ));
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    HandShake handShake;
    handShake.parseInput();
    handShake.minimumTimeToKnowEachOther();
    fout << handShake.getMinimumTime();
    fout.close();
    return 0;
}