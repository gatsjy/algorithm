#include <bits/stdc++.h>

using namespace std;

namespace _20 {
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int N;
		cin >> N;
		vector<int> a(N);
		vector<int> b(N);
		vector<char> battle(N);
		int input;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> b[i];
		}
		// 1. 가위 = 1 / 바위 = 2 / 보 = 3
		// 배틀시작

		for (int i = 0; i < N; i++) {
			if (a[i] == b[i]) {
				cout << "D" << endl;
			}
			else if (a[i] == 1 && b[i] == 3) {
				cout << "A" << endl;
			}
			else if (a[i] == 2 && b[i] == 1) {
				cout << "A" << endl;
			}
			else if (a[i] == 3 && b[i] == 2) {
				cout << "A" << endl;
			}
			else {
				cout << "B" << endl;
			}
		}
		return 0;
	}
}