#include <bits/stdc++.h>

using namespace std;
namespace _10989 {
	int a[10001];
	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			a[tmp]++;
		}
		for (int i = 1; i <= 10000; i++) {
			for (int j = 0; j < a[i]; j++) {
				cout << i << "\n";
			}
		}
		return 0;
	}
}