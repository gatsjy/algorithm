#include <bits/stdc++.h>

using namespace std;

namespace _1717 {

	int n, m;
	vector<int> v;

	// �θ� ã�� �Լ�
	int getParent(int a) {
		if (v[a] == a) return a;
		return v[a] = getParent(v[a]);
	}

	// ���� �ΰ��� ���� ���������� Ȯ���ϴ� �޼���
	bool isUnion(int a, int b) {
		a = getParent(a);
		b = getParent(b);
		if (a == b)return true;
		return false;
	}

	// ��ġ�� �޼���
	void Union(int a, int b) {
		a = getParent(a);
		b = getParent(b);
		if (a < b) v[a] = b;
		else v[b] = a;
	}

	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		cin >> n >> m;
		v.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			v[i] = i;
		}

		int way, a, b;
		for (int i = 0; i < m; i++) {
			cin >> way >> a >> b;
			if (way == 1) {
				if (isUnion(a, b)) {
					cout << "YES" << "\n";
				}
				else
				{
					cout << "NO" << "\n";
				}
			}
			else // way != 0
			{
				if (!isUnion(a, b)) {
					Union(a, b);
				}
			}
		}
		return 0;
	}
}