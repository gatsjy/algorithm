#include <iostream>
#include <vector>

using namespace std;

namespace _11866{
	int main() {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 1; i <= n; i++) {
			a[i - 1] = i;
		}
		cout << "<";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k - 1; j++) {
				a.push_back(a[0]);
				a.erase(a.begin());
			}
			if (i == n - 1) {
				cout << a[0];
			}
			else {
				cout << a[0] << ", ";
			}
			a.erase(a.begin());
		}
		cout << ">";
		return 0;
	}
}