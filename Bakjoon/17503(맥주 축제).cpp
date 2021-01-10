#include <bits/stdc++.h>

using namespace std;
namespace _17503 {
	typedef long long ll;
	typedef pair <ll, ll> beer;

	// 기간, 선호도합, 종류
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

		// 도수 낮은 순으로 정렬
		sort(beers.begin(), beers.end());

		priority_queue <ll> pq;

		// 종류만큼 돌리기
		// 기간, 선호도합, 종류
		// ll n, m, k;
		// 지금 술을 가지고 있는 상황
		// 가지고 있는 술의 가치의 합 = sum
		int sum = 0;
		for (int i = 0; i < k; i++) {
			pq.push(-beers[i].second);
			sum += beers[i].second;
			// 가장 많은 맥주를 먹기 위해서 가지고 있는 맥주 중 가장 가치가 작은 것을 먹어버린다.
			if (pq.size() > n) {
				sum += pq.top();
				pq.pop();
			}
			// 가지고 있느 것의 사이즈와 총 가치가 원하는 수준을 넘는 순간..
			if (pq.size() == n && sum >= m) {
				cout << beers[i].first;
				return 0;
			}
		}
		cout << -1;
		return 0;
	}
}