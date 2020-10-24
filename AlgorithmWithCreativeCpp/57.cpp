#include <bits/stdc++.h>

using namespace std;
namespace _57 {
	void recur2(int x) {
		if (x == 0) return;
		recur2(x / 2);
		cout << x % 2;
	}
	int main() {
		int n;
		cin >> n;
		recur2(n);
		return 0;
	}
}
