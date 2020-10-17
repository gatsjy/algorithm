#include <bits/stdc++.h>

using namespace std;

namespace _14 {
	// 1. ���� �� ������ �Լ�
	int reverse(int x) {
		string tmp = to_string(x);
		string res = "";
		for (int i = tmp.size() - 1; i >= 0; i--) {
			res += tmp[i];
		}
		return stoi(res);
	}

	// 2. �Ҽ����� �Ǻ��ϴ� �Լ�
	bool isPrime(int x) {
		if (x == 1) return false;
		for (int i = 2; i < x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}

	int main() {
		int N;
		int input;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			if (isPrime(reverse(input))) {
				cout << reverse(input) << " ";
			}
		}
		return 0;
	}
}