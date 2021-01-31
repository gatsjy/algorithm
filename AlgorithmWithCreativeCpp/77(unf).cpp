//#include <bits/stdc++.h>
//
//using namespace std;
//namespace _77 {
//	int unf[1001];
//
//	int Find(int v) {
//		if (unf[v] == v) return v;
//		else Find(unf[v]);
//	}
//
//	void Union(int a, int b) {
//		a = Find(a);
//		b = Find(b);
//		if (a != b) unf[a] = b;
//	}
//	int main() {
//		int n, m;
//		cin >> n >> m;
//		for (int i = 1; i <= n; i++) {
//			unf[i] = i;
//		}
//		int a, b;
//		for (int i = 0; i < m; i++) {
//			cin >> a >> b;
//			Union(a, b);
//		}
//
//		cin >> a >> b;
//		int aa = Find(a);
//		int bb = Find(b);
//		if (aa == bb) {
//			cout << "YES";
//		}
//		else {
//			cout << "NO";
//		}
//		return 0;
//	}
//}