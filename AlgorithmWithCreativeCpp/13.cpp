#include<bits/stdc++.h>
using namespace std;
// C:\Users\Gatsjy\source\repos\algorithmstudy\Debug 
typedef long long ll;

ll n;
int sum = 0;
int total;
int a[11];
string s;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - '0']++;
	}

	int mx_cnt = -2147000000;
	int res = -2147000000;
	for (int i = 0; i <= 10; i++) {
		if (mx_cnt <= a[i]) {
			res = i;
			mx_cnt = a[i];
		}
	}
	
	cout << res;
	return 0;
}