#include <bits/stdc++.h>

using namespace std;

namespace _1244 {
	bool ch[101];
	void click(int idx) {
		if (ch[idx] == 1) {
			ch[idx] = 0;
		}
		else {
			ch[idx] = 1;
		}
	}

	int main() {
		int n;
		cin >> n;
		int input;
		for (int i = 1; i <= n; i++) {
			cin >> input;
			ch[i] = input;
		}

		int c;
		cin >> c;
		while (c--) {
			int sex, idx;
			cin >> sex >> idx;
			// 남자일 때
			if (sex == 1) {
				for (int i = 1; i <= n; i++) {
					if (i % idx == 0) {
						click(i);
					}
				}
			}
			else if (sex == 2) {
				// idx를 기준으로 펼칠수있는 길이를 구함
				int width = min(idx - 1, n - idx);
				// width를 기준으로 양옆의 사항을 체크
				int cnt = 0;
				for (int i = 1; i <= width; i++) {
					if (ch[idx - i] == ch[idx + i]) {
						cnt++;
					}
					else {
						break;
					}
				}
				for (int i = 0; i <= cnt; i++) {
					if (i == 0) {
						click(idx);
					}
					else {
						click(idx - i);
						click(idx + i);
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i == n) {
				if (ch[i]) {
					cout << 1;
				}
				else {
					cout << 0;
				}
			}
			else {
				if (ch[i]) {
					cout << 1 << " ";
				}
				else {
					cout << 0 << " ";
				}
			}
		}

		return 0;
	}
}