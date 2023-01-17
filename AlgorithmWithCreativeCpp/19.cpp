//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n;
//int h[101];
//
//int main() {
//	cin >> n;
//	// °Å²Ù·Î
//	for (int i = 0; i < n; i++) {
//		cin >> h[i];
//	}
//	
//	int cnt = 0;
//	int mx = h[n-1];
//	for (int i = n - 1; i > 0; i--) {
//		if (h[i] > mx) {
//			cnt++;
//			mx = h[i];
//		}
//	}
//	cout << cnt;
//
//	return 0;
//}