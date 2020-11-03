#include <bits/stdc++.h>

using namespace std;

namespace _6679 {
	int main() {

		for (int i = 1000; i <= 9999; i++) {
			int sum_10 = 0;
			int tmp_10 = i;
			while (tmp_10) {
				sum_10 += tmp_10 % 10;
				tmp_10 /= 10;
			}
			int sum_12 = 0;
			int tmp_12 = i;
			while (tmp_12) {
				sum_12 += tmp_12 % 12;
				tmp_12 /= 12;
			}
			int sum_16 = 0;
			int tmp_16 = i;
			while (tmp_16) {
				sum_16 += tmp_16 % 16;
				tmp_16 /= 16;
			}
			if (sum_10 == sum_12) {
				if (sum_12 == sum_16) {
					cout << i << endl;
				}
			}
		}
		return 0;
	}
}
