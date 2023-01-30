//#include <bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<ll> v;
//	int tmp;
//	for (int i = 0; i < n; i++) {
//		cin >> tmp;
//		v.push_back(tmp);
//	}
//	ll cluster;
//	cin >> cluster;
//	int res = 0;
//	for (int i = 0; i < n; i++) {
//		if (v[i] == 0) continue;
//		if (v[i] % cluster==0) {
//			res += (v[i] / cluster) * cluster;
//		}
//		else {
//			res += ((v[i] / cluster) + 1) * cluster;
//		}
//	}
//	cout << res;
//	return 0;
//}