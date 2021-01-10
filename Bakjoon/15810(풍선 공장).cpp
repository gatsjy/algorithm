#include <bits/stdc++.h>

using namespace std;

namespace _15810 {
	typedef long long ll;
	typedef pair<ll, ll> balloon;
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		priority_queue<balloon, vector<balloon>, greater<balloon>> pq;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			ll input;
			cin >> input;
			pq.push({ input,input });
		}

		for (int i = 0; i < m - 1; i++) {
			ll first = pq.top().first;
			ll second = pq.top().second;
			pq.pop();
			// 맨 위가 다음초에 만들것의 가장 짧은 시간이 될 것이다.
			pq.push({ first + second,second });
		}

		cout << pq.top().first;
		return 0;
	}
}