#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
namespace _10973 {
	vector<int> v;
	int main() {
		int n;

		cin >> n;
		v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		if (prev_permutation(v.begin(), v.end())) {
			for (int i = 0; i < n; i++) {
				cout << v[i] << " ";
			}
		}
		else {
			cout << -1;
		}
		return 0;
	}
}

