#include <bits/stdc++.h>

using namespace std;

namespace _1107 {
	int n, m, input;
	int ch[10] = { 0, };
	vector<int> buttons;

	int min_res = 2147000000;

	// �׽�Ʈ ���̽� ���� https://www.acmicpc.net/board/view/31853

	void dfs(int level, int size) {
		if (level == size) {
			string tmp;
			for (int i = 0; i < size; i++) {
				tmp.push_back(ch[i] + '0');
				//cout << ch[i];
			}
			//cout << "\n";

			int value = stoi(tmp);
			int res = 0;
			// ���� value �� ũ��
			if (n < value) {
				res = value - n;
			}
			else if (n > value) {
				// ���� n�̴� ũ��
				res = n - value;
			}
			res += to_string(value).size();

			if (min_res > res) {
				//cout << value << "\n";
				min_res = res;
			}

		}
		else {
			for (int j = 0; j < buttons.size(); j++) {
				if (ch[level] == -1) {
					ch[level] = buttons[j];
					dfs(level + 1, size);
					ch[level] = -1;
				}
			}
		}
	}

	int main() {
		cin >> n >> m;

		// ch�� -1�� �ʱ�ȭ
		for (int i = 0; i < 10; i++) {
			ch[i] = -1;
		}

		bool mch[10] = { 0 };
		for (int i = 0; i < m; i++) {
			cin >> input;
			mch[input] = 1;
		}

		for (int i = 0; i < 10; i++) {
			if (!mch[i]) {
				buttons.push_back(i);
			}
		}

		// ���� �ּ��� ����� ���� �ϴ� ���س��´�.
		min_res = abs(n - 100);

		// ����� ���� ���Ѵ�.
		for (int i = 1; i <= 6; i++) {
			dfs(0, i);
		}

		if (100 == n) {
			min_res = 0;
		}
		if (m == 0) {
			if (min_res > to_string(n).size()) {
				min_res = to_string(n).size();
			}
		}

		cout << min_res;

		return 0;
	}
}
