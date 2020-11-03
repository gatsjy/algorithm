#include <bits/stdc++.h>

using namespace std;
namespace _11648 {
	int main() {
		int n;
		cin >> n;
		int cnt = 0;
		while (n > 9) {
			int tmp = n;
			int sum = 1;
			while (tmp > 0) {
				sum *= tmp % 10;
				tmp /= 10;
			}
			n = sum;
			cnt++;
		}
		cout << cnt;
		return 0;
	}
}
