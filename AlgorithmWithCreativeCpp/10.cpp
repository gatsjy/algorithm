#include<bits/stdc++.h>
using namespace std;
// C:\Users\Gatsjy\source\repos\algorithmstudy\Debug 

int n;
int dsum = 0;
int res = 0;
int tmp = 0;
int digit_sum(int x) {
	int res = 0;
	while (x > 0) {
		res += x % 10;
		x /= 10;
	}
	return res;
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		int digits = digit_sum(tmp);
		if (dsum < digits) {
			dsum = digits;
			res = tmp;
		}
		else if(dsum==digits) {
			if (res < tmp) {
				res = tmp;
			}
		}
	}

	cout << res;
	return 0;
}