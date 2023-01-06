
#include<bits/stdc++.h>
using namespace std;
// C:\Users\Gatsjy\source\repos\algorithmstudy\Debug 
string s;
string tmp;

int solve(int input) {
	int total = 0;
	for (int i = 1; i <= input; i++) {
		if (input % i == 0) {
			total++;
		}
	}
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	int cnt = 1;
	int res = 0;
	for (int i = s.size()-1; i >= 0 ; i--) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			res += cnt * (s[i] - '0');
			cnt *= 10;
		}
	}
	cout << res << "\n";
	cout << solve(res);

	return 0;
}