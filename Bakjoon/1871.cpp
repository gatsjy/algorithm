#include <bits/stdc++.h>

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

int main() {
	int c;
	cin >> c;
	string s;
	cin.ignore();
	while (c--) {
		cin >> s;
        vector<string> ss = splitString(s, '-');
        int a = (ss[0][0] - 'A') * 26 * 26 + (ss[0][1] - 'A') * 26 + ss[0][2] - 'A';
        if (abs(a - stoi(ss[1])) <= 100) {
            cout << "nice";
        }
        else {
            cout << "not nice";
        }
        cout << "\n";
	}
    return 0;
}