class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> str;
        str.push("");

        for (int i = 0; i < s.size(); i++){
            if (isdigit(s[i])){
                int n = 0;
                while (isdigit(s[i])){
                    n = n*10 + (s[i]-'0');
                    i++;
                }
                i--;
                num.push(n);
            }
            else if (s[i] == '['){
                str.push("");
            }
            else if (s[i] == ']'){
                int n = num.top();
                num.pop();
                string str1 = str.top();
                str.pop();
                string t = str.top();
                str.pop();
                for (int j = 0; j < n; j++){
                    t += str1;
                }
                str.push(t);
            }
            else{
                string t = str.top();
                str.pop();
                t += s[i];
                str.push(t);
            }
        }

        string ans;
        while(!str.empty()){
            ans += str.top();
            str.pop();
        }

        return ans;
    }
};