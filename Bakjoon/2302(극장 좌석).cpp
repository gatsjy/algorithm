#include <bits/stdc++.h>

using namespace std;
namespace _2302 {
	typedef long long ll;

	// 1�ð� 40�� ���� ó��...
	// https://www.acmicpc.net/problem/2302

	ll seat[41];
	ll dp[41];
	vector<int> vips;
	int n, m, vip;
	int main() {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> vip;
			seat[vip]++;
			vips.push_back(vip);
		}

		// �⺻ ����
		dp[0] = 1;
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (seat[i] == 1) // �ش� �ڸ��� vip�ڸ����?
			{
				dp[i] = 1;
				cnt = 1;
			}
			else // �ش� �ڸ��� vip�ڸ��� �ƴ϶��
			{
				if (cnt == 1) {
					dp[i] = 1;
				}
				else {
					dp[i] = dp[i - 1] + dp[i - 2];
				}
				cnt++;
			}
		}

		ll res = 1;
		for (int i = 0; i < vips.size(); i++) {
			if (vips[i] - 1 < 0) continue;
			res *= dp[vips[i] - 1];
		}
		res *= dp[n]; // ��¥�� 1�� �ʱ�ȭ������..

		cout << res;
		return 0;
	}
}
