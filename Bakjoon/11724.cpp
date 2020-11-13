#include <vector>
#include <iostream>

using namespace std;
namespace _11724 {
	int unf[1001];
	int cnt = 0;
	int Find(int v) {
		if (unf[v] == v)return v;
		else unf[v] = Find(unf[v]);
	}

	void Union(int a, int b) {
		a = Find(a);
		b = Find(b);
		if (a != b) {
			unf[b] = a;
			cnt--;
		}
	}

	int main() {
		int n, m, a, b;
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			unf[i] = i;
		}
		cnt = n;
		for (int i = 1; i <= m; i++) {
			cin >> a >> b;
			if (Find(a) != Find(b)) {
				Union(a, b);
			}
		}

		cout << cnt;

		return 0;
	}
}

