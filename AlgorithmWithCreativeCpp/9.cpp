#include<bits/stdc++.h>
using namespace std;
// C:\Users\Gatsjy\source\repos\algorithmstudy\Debug 

int cnt[50001];

int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j = j + i) {
			cnt[j]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}