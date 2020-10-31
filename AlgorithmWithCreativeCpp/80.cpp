//#include <bits/stdc++.h>
//namespace _82 {
//using namespace std;
//
//#define INF 2147000000;
//
//	int dist[21];
//	int ch[21];
//
//	struct edge {
//		int v;
//		int dist;
//		edge(int a, int b) {
//			v = a;
//			dist = b;
//		}
//		bool operator<(const edge& b) const {
//			return dist > b.dist;
//		}
//	};
//
//	int main() {
//		int n, m;
//		cin >> n >> m;
//		for (int i = 1; i <= n; i++) {
//			dist[i] = INF;
//		}
//		priority_queue<edge> pq;
//		vector<pair<int, int>> v[21];
//		int a, b, c;
//		for (int i = 0; i < m; i++) {
//			cin >> a >> b >> c;
//			v[a].push_back({ b,c });
//		}
//		pq.push(edge(1, 0));
//		dist[1] = 0;
//		while (!pq.empty()) {
//			int now = pq.top().v;
//			int cost = pq.top().dist;
//			pq.pop();
//			if (cost > dist[now]) continue;
//			for (int i = 0; i < v[now].size(); i++) {
//				int next = v[now][i].first;
//				int nextDist = cost + v[now][i].second;
//				if (dist[next] > nextDist) {
//					dist[next] = nextDist;
//					pq.push(edge(next, nextDist));
//				}
//			}
//		}
//		return 0;
//	}
//}