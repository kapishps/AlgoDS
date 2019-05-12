#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

/*
 * Complete the 'crusher' function below.
 * It must modify the argument passed to it.
 */
#include<stack>

void crusher(list<string>& data) {
    stack<pair<string, int>> st;
    string prev;
    int cnt = 0;
    for (auto i : data) {
        if (!st.empty() && st.top().first == i) {
            st.top().second++;
        } else {
            if (st.empty()) {
                st.push({i, 1});
            } else {
                if (st.top().first == "MANGO" && st.top().second >= 2) {
                    st.pop();
                    if (!st.empty() && st.top().first == i) {
                        st.top().second++;
                    } else {
                        st.push({i, 1});
                    }
                } else if (st.top().first == "ORANGE" && st.top().second >= 3) {
                    st.pop();
                    if (!st.empty() && st.top().first == i) {
                        st.top().second++;
                    } else {
                        st.push({i, 1});
                    }
                } else if (st.top().first == "PAAN" && st.top().second >= 4) {
                    st.pop();
                    if (!st.empty() && st.top().first == i) {
                        st.top().second++;
                    } else {
                        st.push({i, 1});
                    }
                } else if (st.top().first == "CHOCOLATE" && st.top().second >= 5) {
                    st.pop();
                    if (!st.empty() && st.top().first == i) {
                        st.top().second++;
                    } else {
                        st.push({i, 1});
                    }
                } else if (st.top().first == "COFFEE" && st.top().second >= 5) {
                    st.pop();
                    if (!st.empty() && st.top().first == i) {
                        st.top().second++;
                    } else {
                        st.push({i, 1});
                    }
                } else if (st.top().first == "MINT" && st.top().second >= 6) {
                    st.pop();
                    if (!st.empty() && st.top().first == i) {
                        st.top().second++;
                    } else {
                        st.push({i, 1});
                    }
                }
                else{
                    st.push({i, 1});
                }
            }
        }
    }

    data.clear();
    while (!st.empty()) {
        if (st.top().first == "MANGO" && st.top().second >= 2) {
            st.pop();
            continue;
        } else if (st.top().first == "ORANGE" && st.top().second >= 3) {
            st.pop();
            continue;
        } else if (st.top().first == "PAAN" && st.top().second >= 4) {
            st.pop();
            continue;
        } else if (st.top().first == "CHOCOLATE" && st.top().second >= 5) {
            st.pop();
            continue;
        } else if (st.top().first == "COFFEE" && st.top().second >= 5) {
            st.pop();
            continue;
        } else if (st.top().first == "MINT" && st.top().second >= 6) {
            st.pop();
            continue;
        } else {
            while (st.top().second--){
                data.push_front(st.top().first);
            }
        }
        st.pop();
    }
    return;
}

