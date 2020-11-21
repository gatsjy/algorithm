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
		// ���̳ʽ� ó��
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

		// �÷��� ó��
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

		// 1�� �ΰ��� ����� ���ϸ� �����̴� �׷��Ƿ� ī��Ʈ�� ���� �����ش�.
		sum += one.size();

		cout << sum;
		return 0;
	}
}
