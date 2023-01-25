//#include <bits/stdc++.h>
//
//using namespace std;
//
//int c,n;
//int main() {
//	cin >> c;
//	while (c--) {
//		vector<int> v;
//		for (int i = 0; i < 7; i++) {
//			cin >> n;
//			v.push_back(n);
//		}
//		sort(v.begin(), v.end(), greater<>());
//		int res = 0;
//		int sum = 0;
//		for (int i = 0; i < 7; i++) {
//			if (!(v[i] % 2)) {
//				sum += v[i];
//				res = v[i];
//			}
//		}
//		cout << sum << " " << res << "\n";
//	}
//
//	return 0;
//}