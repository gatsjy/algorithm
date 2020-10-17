#include <bits/stdc++.h>

using namespace std;

namespace _17 {
	int main() {
		int N;
		cin >> N;
		while (N--) {
			int card, cardSum;
			cin >> card >> cardSum;
			int mySum = (1 + card) * card / 2;
			if (mySum == cardSum) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		return 0;
	}
}