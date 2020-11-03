#include <bits/stdc++.h>

using namespace std;

namespace _1551 {
	int main() {
		int n, k;
		cin >> n >> k;
		string input;
		vector<int> a;
		cin >> input;
		string tmp = "";
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == ',') {
				a.push_back(stoi(tmp));
				tmp = "";
			}
			else {
				tmp += input[i];
			}
		}
		a.push_back(stoi(tmp));
		while (k--) {
			vector<int> tmp(a.size() - 1);
			for (int i = 0; i < a.size() - 1; i++) {
				tmp[i] = a[i + 1] - a[i];
			}
			a = tmp;
		}

		for (int i = 0; i < a.size(); i++) {
			if (i == a.size() - 1) {
				cout << a[i];
			}
			else {
				cout << a[i] << ",";
			}
		}
		return 0;
	}
}
