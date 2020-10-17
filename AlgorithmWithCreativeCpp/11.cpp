#include <bits/stdc++.h>

using namespace std;

namespace _11 {
	int main() {
		int N;
		cin >> N;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += to_string(i).size();
		}
		cout << cnt;
		return 0;
	}
}
