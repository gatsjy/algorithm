#include <bits/stdc++.h>

using namespace std;

namespace _15969 {
	int main() {
		int n;
		cin >> n;
		int max = -2147000000;
		int min = 2147000000;
		int input;
		for (int i = 0; i < n; i++) {
			cin >> input;
			if (max < input) max = input;
			if (min > input) min = input;
		}
		cout << max - min;
		return 0;
	}
}
