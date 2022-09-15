#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c;

// 이거 로직 분석해보기
ll pow(ll a, ll b) {
	if (b == 1) return a % c;

	ll ret = pow(a, b / 2);
	ret = (ret * ret) % c;
	if (b % 2) ret = (ret * a) % c;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
	cin >> a >> b >> c;

	cout << pow(a, b) << "\n";

	return 0;
}
