#include<bits/stdc++.h>
using namespace std;
// C:\Users\Gatsjy\source\repos\algorithmstudy\Debug 

int n;
int sum = 0;
int main(){
	cin >> n;

	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		for (int i = 0; i < s.size(); i++) {
			sum++;
		}
	}

	cout << sum;
	return 0;
}