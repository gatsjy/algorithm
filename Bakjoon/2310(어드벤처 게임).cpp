#include <bits/stdc++.h>

// 아무리 찾아본 코드라도 내 손으로 짤 수 없으면 내것이 아니다!

using namespace std;

struct Person {
	int money = 0;
	int cur = 1;
};

vector<pair<string, int>> rooms;
vector<vector<int>> graph;
int ch[1001];
int n;
string s;
int a, b;

void dfs(int v, Person& p, bool& flag) {
	if (flag) return;
	ch[v] = 1;
	p.cur = v;
	//if (p.cur == n) {
	//	flag = true;
	//	return;
	//}
	if (rooms[v].first == "E") {
		for (int i = 0; i < graph[v].size(); i++) {
			int next = graph[v][i];
			if (ch[next] == 0) {
				dfs(next, p, flag);
			}
		}
	}
	else if (rooms[v].first == "L") {
		if (p.money < rooms[v].second) {
			p.money = rooms[v].second;
		}
		for (int i = 0; i < graph[v].size(); i++) {
			int next = graph[v][i];
			if (ch[next] == 0) {
				dfs(next, p, flag);
			}
		}
	}
	else if (rooms[v].first == "T") {
		if (p.money < rooms[v].second) {
			flag = true;
			return;
		}
		else {
			p.money -= rooms[v].second;
			for (int i = 0; i < graph[v].size(); i++) {
				int next = graph[v][i];
				if (ch[next] == 0) {
					dfs(next, p, flag);
				}
			}
		}
	}
}
int main() {
	while (1) {
		cin >> n;
		if (n == 0) break;
		rooms.clear();
		rooms.push_back({ "0",0 }); // 더미 넣어준다.
		graph.clear();
		graph.resize(n + 1);
		memset(ch, 0, sizeof(ch));
		for (int i = 1; i <= n; i++) {
			cin >> s >> a;
			rooms.push_back({ s,a });
			while (1) {
				cin >> b;
				if (b == 0) break;
				graph[i].push_back(b);
			}
		}
		Person person;
		bool flag = false;
		dfs(1, person, flag);
		if (person.cur == n) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}

	return 0;
}