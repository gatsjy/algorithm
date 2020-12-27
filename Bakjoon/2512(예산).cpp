#include<bits/stdc++.h>

using namespace std;

namespace _2512 {
	vector<long long> v;
	long long budget;
	int n;
	long long res = -1;
	int main() {
		cin >> n;
		v.resize(n);
		long long lt = 1;
		long long rt = -1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			rt = max(rt, v[i]);

		}
		cin >> budget;

		while (lt <= rt) {
			long long mid = (lt + rt) / 2;
			long long tbudget = 0;
			for (int i = 0; i < n; i++) {
				tbudget += min(v[i], mid);
			}
			if (tbudget > budget) // �ӽð��� ���������� ũ�� ���� ���� Ž��
			{
				rt = mid - 1;
			}
			else {
				lt = mid + 1;
				// ������ ���� �ٶ󺸸鼭 �ö󰡾� �ϴϱ�...
				// �ӽ� budget�� ������ �װ��� ������ ����� �� �� ����.
				res = max(res, mid);
			}
		}
		cout << res;
		return 0;
	}
}