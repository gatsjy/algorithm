#include <bits/stdc++.h>

using namespace std;
namespace _10974 {
	int N;
	vector<int> v;
	int main() {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			v.push_back(i);
		}

		do {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << "\n";
		} while (next_permutation(v.begin(), v.end()));
		return 0;
	}
}
