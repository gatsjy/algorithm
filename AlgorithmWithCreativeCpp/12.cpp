#include<bits/stdc++.h>
using namespace std;
// C:\Users\Gatsjy\source\repos\algorithmstudy\Debug 

int n;
int sum = 0;
int total;
int main() {
	cin >> n;

	int t_size = to_string(n).size();
	
	// 1~9 9개
	// 10~99 90개
	// 100~999 900개
	// 10000~9999 9000개
	// 규칙 알았으니 로직짜서 긔
	int mul = 1;
	for (int i = 1; i < t_size; i++) {
		total += (9 * mul)*i;
		mul *= 10;
	}

	total += (n - mul + 1) * t_size;

	cout << total;

	return 0;
}