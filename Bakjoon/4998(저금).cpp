#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
double n, b,m;
int main() {
	//while (1) {
	for(int i = 0 ; i < 2; i ++){
		cin >> n >> b >> m;
		ll res = n * (1 + b / 100);
		int cnt = 1;
		while (1) {
			if (res <= m) {
				cnt++;
				res *= (1 + b / 100);
			}
			else {
				break;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}