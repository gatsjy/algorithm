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

				// ���� ���ڰ� ���������� �ι� ���� �ȵǳ�, ee �� oo�� ����Ѵ�.
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
			else // �����϶�
			{
				vowelCnt = 0;
				consonantCnt++;
			}

				// 2. ������ 3�� Ȥ�� ������ 3�� �������� ���� �ȵȴ�.
			if (consonantCnt == 3 || vowelCnt == 3)
			{
				flag = false;
				break;
			}
		}
		// 1. ����(a,e,i,o,u) �ϳ��� �ݵ�� �����Ͽ��� �Ѵ�.
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