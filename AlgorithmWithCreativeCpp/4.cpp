#include<bits/stdc++.h>
using namespace std;

int n, m, sum;

vector<int> a;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		a.push_back(m);
	}
	sort(a.begin(), a.end());
	cout << a[a.size() - 1] - a[0];
	return 0;
}