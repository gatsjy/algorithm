#include <bits/stdc++.h>

using namespace std;

namespace _1213 {
	string s;
	int ch[26];
	string res;

	// �Ӹ����..
	// ABACABA = AAAABBC -> 4A 2B 1C -> AAB C BAA
	// AABBBBC -> 2A 4C B -> B ���� ������ 2 -> A 2C ACC B CCA
	// �ϳ��� �� ĳġ -> ���Ͱ� �ֱ�
	// ���� ������ ���� �ִ� ���鸸 ��� ��Ƽ� ����� ���ʴ��...
	int main() {
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			ch[s[i] - 'A']++;
		}

		int isPalin = 0;
		int isCenterIdx = 0;
		for (int i = 0; i < 26; i++) {
			if (ch[i] % 2 == 1) { // Ȧ���� 2�� �̻��̸� �Ӹ������ �ƴϴ�.
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
