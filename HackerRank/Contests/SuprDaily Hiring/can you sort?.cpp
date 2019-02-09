#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'customSort' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void customSort(vector<int> arr) {
    int n=arr.size();
    map<int, int> map1;
    for (int i = 0; i < n; ++i) {
        map1[arr[i]]++;
    }
    vector<pair<int,int>> v;
    for (auto i : map1) {
        for (int j = 0; j < i.second; ++j) {
            v.push_back({i.second, i.first});
        }
    }

    sort(v.begin(),v.end());

    for (int j = 0; j < v.size(); ++j) {
        cout << v[j].second << "\n";
    }
}

int main()
{
    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    customSort(arr);

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
