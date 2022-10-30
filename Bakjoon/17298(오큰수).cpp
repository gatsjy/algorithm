#include <bits/stdc++.h>

using namespace std;

int a[1000004];
int ret[1000004];
int n;
stack<int> st;
int main() {
	cin >> n;
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (!st.empty() && ret[st.top()] < a[i]) {
			ret[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 1; i <= n; i++) {
		cout << ret[i] << " ";
	}

	return 0;
}