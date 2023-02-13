#include <bits/stdc++.h>

using namespace std;

int n;

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
	cin >> n;
	while (n--) {
		string s;
        getline(cin, s);
        vector<string> v = splitString(s,' ');
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += stoi(v[i]);
        }
        cout << sum << "\n";
	}

	return 0;
}