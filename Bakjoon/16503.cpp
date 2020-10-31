#include <bits/stdc++.h>

namespace _16503 {
    using namespace std;
    vector<string> splitString(string str, char delimeter) {
        vector<string> res;
        string tmp = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == delimeter) {
                res.push_back(tmp);
                tmp = "";
            }
            else if (str[i] != delimeter) {
                tmp += str[i];
            }
        }
        res.push_back(tmp);
        return res;
    }

    int cal(string s1, string s2, string s3) {
        if (s2 == "+") {
            return stoi(s1) + stoi(s3);
        }
        else if (s2 == "/") {
            return stoi(s1) / stoi(s3);
        }
        else if (s2 == "*") {
            return stoi(s1) * stoi(s3);
        }
        else {
            return stoi(s1) - stoi(s3);
        }
    }
    int main() {
        string s;
        getline(cin, s);
        vector<string> ss = splitString(s, ' ');
        vector<string> number;
        vector<string> op;
        for (int i = 0; i < ss.size(); i++) {
            if (ss[i] == "+" || ss[i] == "*" || ss[i] == "/" || ss[i] == "-") {
                op.push_back(ss[i]);
            }
            else {
                number.push_back(ss[i]);
            }
        }
        int s1 = cal(to_string(cal(number[0], op[0], number[1])), op[1], number[2]);
        int s2 = cal(number[0], op[0], to_string(cal(number[1], op[1], number[2])));
        cout << min(s1, s2) << endl;
        cout << max(s1, s2) << endl;
    }
}