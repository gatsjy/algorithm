#include <bits/stdc++.h>

using namespace std;

int v, e, k;
vector<pair<int,int>> a[20001];
int dist[20001] = {0,};
priority_queue<pair<int,int>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		int start, end, value;
		cin >> start >> end >> value;
		a[start].push_back(make_pair(end,value));
	}

	// 
	for (int i = 1; i <= v; i++) {
		dist[i] = 2147000000;
	}
	// 출발 도시 설정
	dist[k] = 0;
	pq.push({ 0, k });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int value = -pq.top().first;
		pq.pop();
		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i].first;
			int nextvalue = a[cur][i].second;
			if (dist[next] > value + nextvalue)
			{
				dist[next] = value + nextvalue;
				pq.push({ -dist[next], next });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == 2147000000) {
			cout << "INF" << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

	return 0;
}