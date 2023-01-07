#include<bits/stdc++.h>
using namespace std;
// C:\Users\Gatsjy\source\repos\algorithmstudy\Debug 
string s;
string tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			continue;
		}
		else if(s[i] >='A' and s[i] <= 'Z'){
			tmp += s[i]+32;
		}
		else {
			tmp += s[i];
		}
	}

	cout << tmp;
	return 0;
}