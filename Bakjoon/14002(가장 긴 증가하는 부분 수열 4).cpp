#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;
namespace _14002 {
	int a[1001];
	int dp[1001] = { 0,1 };
	int res = 0;

	int ch[1001];
	int n;
	stack<int> st;
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		for (int i = 2; i <= n; i++) {
			int tmp = 1;
			for (int j = 1; j < i; j++) {
				if (a[i] > a[j]) {
					tmp = max(tmp, dp[j] + 1);
				}
			}
			dp[i] = tmp;
		}

		for (int i = 1; i <= n; i++) {
			if (dp[i] > res) res = dp[i];
		}

		for (int i = n; i > 0; i--) {
			if (res == 0) break;
			if (dp[i] == res) {
				st.push(a[i]);
				res--;
			}
		}

		cout << st.size() << '\n';
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		return 0;
	}
}

