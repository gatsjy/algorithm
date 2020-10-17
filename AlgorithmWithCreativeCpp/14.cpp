#include <bits/stdc++.h>

using namespace std;

namespace _14 {
	// 1. 들어온 수 뒤집는 함수
	int reverse(int x) {
		string tmp = to_string(x);
		string res = "";
		for (int i = tmp.size() - 1; i >= 0; i--) {
			res += tmp[i];
		}
		return stoi(res);
	}

	// 2. 소수인지 판별하는 함수
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