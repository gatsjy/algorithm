#include <bits/stdc++.h>

namespace _11098 {
	using namespace std;

struct player {
	string name;
	long price;
	player(string s, long p) {
		name = s;
		price = p;
	}
	bool operator<(const player& b) const {
		return price < b.price;
	}
};
int main() {
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		priority_queue<player> pq;
		long price;
		string name;
		for (int i = 0; i < n; i++) {
			cin >> price >> name;
			pq.push(player(name, price));
		}
		cout << pq.top().name << endl;
	}
	return 0;
}