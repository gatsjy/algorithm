#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> a;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			// & ���� -> �����ϴ� ��Ʈ�� ��� 1�̸� 1��ȯ -> �׷��Ƿ� ���� �������� üũ�� �� �ִ�.
			// ������� ��ü���� �ش� ��Ʈ�� �κ��������� �� �� �ִ� ���̴�.
			//if (i & (1 << j)) {
			//	cout << "1";
			//}
			//else {
			//	cout << "0";
			//}
			if (i & (1 << j)) {
				sum += a[j];
			}
		}
		if (sum == s) cnt++;
		//cout << "\n";
	}
	cout << cnt;
	return 0;
}