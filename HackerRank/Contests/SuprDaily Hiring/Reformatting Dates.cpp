#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'reformatDate' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY dates as parameter.
 */

vector<string> reformatDate(vector<string> dates) {

    vector<string> ret;
    map<string, string> month, day;
    month["Jan"] = "01";
    month["Feb"] = "02";
    month["Mar"] = "03";
    month["Apr"] = "04";
    month["May"] = "05";
    month["Jun"] = "06";
    month["Jul"] = "07";
    month["Aug"] = "08";
    month["Sep"] = "09";
    month["Oct"] = "10";
    month["Nov"] = "11";
    month["Dec"] = "12";

    day["1st"] = "01";
    day["2nd"] = "02";
    day["3rd"] = "03";
    day["4th"] = "04";
    day["5th"] = "05";
    day["6th"] = "06";
    day["7th"] = "07";
    day["8th"] = "08";
    day["9th"] = "09";

    for (int i = 0; i < dates.size(); ++i) {
        stringstream ss(dates[i]);
        string dt, mnth, ans, yr;
        ss >> dt;
        ss >> mnth;
        ss >> yr;
        ans += yr;
        ans += "-";
        ans += month[mnth];
        ans += "-";
        if (dt.size() == 4)
            ans += dt.substr(0, 2);
        else
            ans += day[dt];
        ret.push_back(ans);
    }

    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string dates_count_temp;
    getline(cin, dates_count_temp);

    int dates_count = stoi(ltrim(rtrim(dates_count_temp)));

    vector<string> dates(dates_count);

    for (int i = 0; i < dates_count; i++) {
        string dates_item;
        getline(cin, dates_item);

        dates[i] = dates_item;
    }

    vector<string> result = reformatDate(dates);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
