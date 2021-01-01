#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> a;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			// & 연산 -> 대응하는 비트가 모두 1이면 1반환 -> 그러므로 둘이 같은지를 체크할 수 있다.
			// 예를들면 전체에서 해당 비트가 부분집합인지 알 수 있단 말이다.
			//if (i & (1 << j)) {
			//	cout << "1";
			//}
			//else {
			//	cout << "0";
			//}
			if (i & (1 << j)) {
				sum += a[j];
			}
		}
		if (sum == s) cnt++;
		//cout << "\n";
	}
	cout << cnt;
	return 0;
}