#include <bits/stdc++.h>

using namespace std;
int c,n;
string s;
bool ch[21];
// 1. set���� Ǯ�� -> ����
// 2. bool�� Ǯ��
// 3. ��Ʈ����ŷ���� Ǯ��??
// ���� https://donggoolosori.github.io/2020/09/24/boj-11723/
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c;

	while (c--) {
		cin >> s;
		if (s == "add") // add
		{
			cin >> n;
			if (ch[n] == 0) ch[n] = 1;
		}
		else if (s[0] == 'c') // check
		{

		}
		else if (s[0] == 'r') // remove
		{

		}
		else if (s == "all") // all
		{

		}
		else if (s[0] == 'e') // empty
		{

		}
		else if (s[0] == 't') // toggle
		{

		}
	}
	return 0;
}