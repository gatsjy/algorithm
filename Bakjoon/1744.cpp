#include <bits/stdc++.h>

using namespace std;

namespace _1744 {
	int main() {

		vector<int> minus;
		vector<int> plus;
		vector<int> one;
		vector<int> zero;

		int n, input;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> input;
			if (input > 0) {
				if (input == 1) {
					one.push_back(input);
				}
				else {
					plus.push_back(input);
				}
			}
			else if (input == 0) {
				zero.push_back(input);
			}
			else if (input < 0) {
				minus.push_back(input);
			}
		}

		sort(minus.begin(), minus.end(), greater<int>());
		sort(plus.begin(), plus.end());

		int sum = 0;
		// 마이너스 처리
		if (minus.size() % 2 == 0) {
			for (int i = 0; i < minus.size(); i += 2) {
				sum += minus[i] * minus[i + 1];
			}
		}
		else if (minus.size() % 2 == 1) {
			if (!zero.size()) {
				sum += minus[0];
			}
			if (minus.size()) {
				for (int i = 1; i < minus.size(); i += 2) {
					sum += minus[i] * minus[i + 1];
				}
			}
		}

		// 플러스 처리
		if (plus.size() % 2 == 0) {
			for (int i = 0; i < plus.size(); i += 2) {
				sum += plus[i] * plus[i + 1];
			}
		}
		else if (plus.size() % 2 == 1) {
			sum += plus[0];
			if (plus.size()) {
				for (int i = 1; i < plus.size(); i += 2) {
					sum += plus[i] * plus[i + 1];
				}
			}
		}

		// 1은 두개로 나누어서 곱하면 손해이다 그러므로 카운트한 수를 더해준다.
		sum += one.size();

		cout << sum;
		return 0;
	}
}
