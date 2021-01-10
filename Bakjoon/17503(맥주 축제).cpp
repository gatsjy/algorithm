#include <bits/stdc++.h>

using namespace std;
namespace _17503 {
	typedef long long ll;
	typedef pair <ll, ll> beer;

	// �Ⱓ, ��ȣ����, ����
	ll n, m, k;
	ll v, c;
	vector<beer> beers;
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n >> m >> k;

		for (int i = 0; i < k; i++) {
			cin >> v >> c;
			beers.push_back({ c,v });
		}

		// ���� ���� ������ ����
		sort(beers.begin(), beers.end());

		priority_queue <ll> pq;

		// ������ŭ ������
		// �Ⱓ, ��ȣ����, ����
		// ll n, m, k;
		// ���� ���� ������ �ִ� ��Ȳ
		// ������ �ִ� ���� ��ġ�� �� = sum
		int sum = 0;
		for (int i = 0; i < k; i++) {
			pq.push(-beers[i].second);
			sum += beers[i].second;
			// ���� ���� ���ָ� �Ա� ���ؼ� ������ �ִ� ���� �� ���� ��ġ�� ���� ���� �Ծ������.
			if (pq.size() > n) {
				sum += pq.top();
				pq.pop();
			}
			// ������ �ִ� ���� ������� �� ��ġ�� ���ϴ� ������ �Ѵ� ����..
			if (pq.size() == n && sum >= m) {
				cout << beers[i].first;
				return 0;
			}
		}
		cout << -1;
		return 0;
	}
}