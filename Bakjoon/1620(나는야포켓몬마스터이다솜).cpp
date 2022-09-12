#include <bits/stdc++.h>

using namespace std;

int n, k;
map<string, int> m1;
map<int, string> m2;
string poke[100004];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m1[s] = i + 1;
		m2[i + 1] = s;
		poke[i + 1] = s;
	}

	for (int i = 0; i < k; i++) {
		cin >> s;
		if (atoi(s.c_str()) == 0) // 입력값이 문자열
		{
			cout << m1[s] << "\n";
		}
		else 
		{
			cout << poke[atoi(s.c_str())] << "\n";
		}
	}
	return 0;
}
