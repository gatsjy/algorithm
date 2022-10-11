//#include <bits/stdc++.h>
//
//using namespace std;
//
//int visited[251][251];
//char a[251][251];
//int n, m;
//vector<pair<int, int>> v;
//int dy[4] = { 0,1,0,-1 };
//int dx[4] = { -1,0,1,0 };
//string s;
//int sheep, wolf;
//int tsheep, twolf;
//
//void dfs(int y, int x) {
//	visited[y][x] = 1;
//	if (a[y][x] == 'v') wolf++;
//	if (a[y][x] == 'o') sheep++;
//	for (int i = 0; i < 4; i++) {
//		int ny = dy[i] + y;
//		int nx = dx[i] + x;
//		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || a[ny][nx] == '#') continue;
//		dfs(ny, nx);
//	}
//	return;
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		getline(cin, s);
//		for (int j = 0; j < s.size(); j++) {
//			a[i][j] = s[j];
//		}
//	}
//
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (a[i][j] != '#' && !visited[i][j]) {
//				sheep = 0;
//				wolf = 0;
//				dfs(i, j);
//				if (sheep > wolf) {
//					tsheep += sheep;
//				}
//				else {
//					twolf += wolf;
//				}
//				//cnt++;
//				//cout <<cnt << " " << sheep << " " << wolf << "\n";
//			}
//		}
//	}
//
//	cout << tsheep << "\n";
//	cout << twolf;
//
//	return 0;
//}