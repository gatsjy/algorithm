#include <bits/stdc++.h>

using namespace std;

namespace _9466 {
	int n;
	vector<int> maxNum;
	vector<int> minNum;
	string comp;
	bool isValid(vector<int>& num) {
		for (int i = 0; i < comp.size(); i++) {
			if (comp[i] == '<' && num[i] > num[i + 1]) {
				return false;
			}
			else if (comp[i] == '>' && num[i] < num[i + 1]) {
				return false;
			}
		}
		return true;
	}

	int main() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			comp += c;
		}

		for (int i = 9; i > 9 - (n + 1); i--) {
			maxNum.push_back(i);
		}
		for (int i = 0; i < n + 1; i++) {
			minNum.push_back(i);
		}

		// 최댓값을 구한다.
		while (1) {
			if (isValid(maxNum)) {
				break;
			}
			prev_permutation(maxNum.begin(), maxNum.end());
		}

		// 최소값을 구한다.
		while (1) {
			if (isValid(minNum)) {
				break;
			}
			next_permutation(minNum.begin(), minNum.end());
		}

		for (int i = 0; i < maxNum.size(); i++) {
			cout << maxNum[i];
		}
		cout << "\n";
		for (int i = 0; i < minNum.size(); i++) {
			cout << minNum[i];
		}

		return 0;
	}
}
