//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//	int n,k;
//	cin >> n;
//	vector<int> a(n);
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	cin >> k;
//
//	int cur = 0;
//	while (k--) {
//		if (cur == -1) break;
//		if (cur == a.size()) cur = 0;
//		if (a[cur] > 0) {
//			a[cur] -= 1;
//			cur++;
//		}
//		else if(a[cur] == 0) {
//			while (a[cur] == 0) {
//				cur++;
//				if (cur == a.size()) {
//					cur = -1;
//					break;
//				}
//			}
//		}
//	}
//
//	cout << cur + 1;
//
//	return 0;
//}