#include <bits/stdc++.h>

using namespace std;

namespace _9 {
	int cnt[50001] = { 0, };
	// 1. �Ʒ��� �Լ��� ���� Ÿ�� ������ ����. 
	int countDivisor(int n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (n % i == 0) cnt++;
		}
		return cnt;
	}

	// 2. �׷��ٸ� ��� ��� �ұ�?
	// �ϳ��ϳ� ���� �ֱ� �����Ѵ�.
	void main() {
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j = i + j) {
				cnt[j]++;
			}
		}
		for (int i = 1; i <= N; i++) {
			cout << cnt[i] << " ";
		}
	}
}