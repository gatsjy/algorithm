#include <bits/stdc++.h>

using namespace std;

string s;
int main() {
	while (true) {
		cin >> s;
		if (s == "end") return 0;
		bool flag = true;

		int aeiouCnt = 0;
		int vowelCnt = 0;
		int consonantCnt = 0;
		char prev = '-';

		for (int i = 0; i < s.size(); i++) {
			if (i != 0) {
				prev = s[i - 1];

				// 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
				if (prev == s[i])
				{
					if (!(s[i] == 'e' || s[i] == 'o'))
					{
						flag = false;
						break;
					}
				}
			}

			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				aeiouCnt++;
				vowelCnt++;
				consonantCnt = 0;
			}
			else // 자음일때
			{
				vowelCnt = 0;
				consonantCnt++;
			}

				// 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안된다.
			if (consonantCnt == 3 || vowelCnt == 3)
			{
				flag = false;
				break;
			}
		}
		// 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
		if (aeiouCnt == 0)
		{
			flag = false;
		}

		if (flag)
		{
			cout << "<" + s + "> is acceptable." << "\n";
		}
		else
		{
			cout << "<" + s + "> is not acceptable." << "\n";
		}
	}
	return 0;
}