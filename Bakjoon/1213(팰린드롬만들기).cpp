#include <bits/stdc++.h>

using namespace std;

namespace _1213 {
	string s;
	int ch[26];
	string res;

	// 팰린드롬..
	// ABACABA = AAAABBC -> 4A 2B 1C -> AAB C BAA
	// AABBBBC -> 2A 4C B -> B 빼고 나누기 2 -> A 2C ACC B CCA
	// 하나인 것 캐치 -> 센터값 넣기
	// 앞의 값들은 그저 있는 값들만 모두 모아서 만들기 차례대로...
	int main() {
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			ch[s[i] - 'A']++;
		}

		int isPalin = 0;
		int isCenterIdx = 0;
		for (int i = 0; i < 26; i++) {
			if (ch[i] % 2 == 1) { // 홀수가 2개 이상이면 팰린드롭이 아니다.
				isPalin++;
				isCenterIdx = i;
			}
		}

		if (isPalin > 1) {
			cout << "I'm Sorry Hansoo";
		}
		else {
			string tmp = "";
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < ch[i] / 2; j++) {
					tmp += i + 'A';
				}
			}
			char center = isCenterIdx + 'A';
			string pre = tmp;
			reverse(tmp.begin(), tmp.end());
			if (s.size() % 2 == 0) {
				res = pre + tmp;
			}
			else {
				res = pre + center + tmp;
			}
			cout << res;
		}
		return 0;
	}
}
