#include <bits/stdc++.h>

using namespace std;

namespace _����Լ��������� {
	void dfs(int n) {
		if (n == 3) {
			cout << "��ͳ�" << "\n";
			return;
		}
		cout << n << "��Ϳ���" << n + 1 << "��ȣ���մϴ�." << "\n";
		dfs(n + 1);
		cout << n << "��° ��� ��" << "\n";
	}

	int main() {
		dfs(0);
		return 0;
	}
}
