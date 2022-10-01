#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
ll n;
int t;

int solution(ll n) {
	int cnt2 = n/2;
	int tmpcnt2 = n / 2;
	int cnt5 = 0;
	int tmpcnt5 = n / 5;
	
	// 2의 갯수 카운트
	int counter = 2;
	for (int i = 4; i <= n; i *= 2) {
		cnt2 += (tmpcnt2 / 2) * counter;
		tmpcnt2 /= 2;
		counter++;
	}

	// 5의 갯수 카운트
	counter = 0;
	for (int i = 5; i <= n; i *= 5) {
		if (i == 5) {
			cnt5 += tmpcnt5;
		}
		else {
			cnt5 += (cnt5 / 5) * counter;
		}
		tmpcnt5 /= 5;
		counter++;
	}

	return min(cnt2, cnt5);
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int res = solution(n);
		cout << res << "\n";
	}
	return 0;
}