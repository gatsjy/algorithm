#include <bits/stdc++.h>

using namespace std;

namespace _1213 {
	string s;

	int main() {

		cin >> s;

		char ch[26] = { 0, };
		for (int i = 0; i < s.size(); i++) {
			ch[s[i] - 'A']++;
		}

		// 팰린드롬 만들수 있는지 확인
		int check = 0;
		for (int i = 0; i < 26; i++) {
			if (ch[i] % 2) {
				check++;
			}
		}

		if (check > 1) {
			cout << "I'm Sorry Hansoo";
			return 0;
		}
		else {
			string tmp = "";
			char ctmp = '0';
			for (int i = 0; i < 26; i++) {
				if (ch[i] % 2) {
					ctmp = i + 'A';
					ch[i]--;
				}
			}
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < ch[i] / 2; j++) {
					tmp += i + 'A';
				}
			}
			string ntmp = tmp;
			reverse(tmp.begin(), tmp.end());
			if (check == 1) {
				ntmp += ctmp;
			}
			ntmp += tmp;
			cout << ntmp;
		}
		return 0;
	}
}