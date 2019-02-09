#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'finalPrice' function below.
 *
 * The function accepts INTEGER_ARRAY prices as parameter.
 */

void finalPrice(vector<int> prices) {
    vector<int> sml(prices.size());
    vector<int> ind;
    stack<int> st;
    long long cost = 0;
    for (int i = prices.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() > prices[i])
            st.pop();
        if (st.empty()) {
            ind.push_back(i);
            sml[i] = prices[i];
        } else {
            sml[i] = prices[i] - st.top();
        }
        st.push(prices[i]);
        cost += sml[i];
    }

    sort(ind.begin(), ind.end());
    cout << cost << "\n";
    for (int i = 0; i < ind.size(); ++i) {
        cout << ind[i] << " ";
    }
}

int main()
{
    string prices_count_temp;
    getline(cin, prices_count_temp);

    int prices_count = stoi(ltrim(rtrim(prices_count_temp)));

    vector<int> prices(prices_count);

    for (int i = 0; i < prices_count; i++) {
        string prices_item_temp;
        getline(cin, prices_item_temp);

        int prices_item = stoi(ltrim(rtrim(prices_item_temp)));

        prices[i] = prices_item;
    }

    finalPrice(prices);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}
