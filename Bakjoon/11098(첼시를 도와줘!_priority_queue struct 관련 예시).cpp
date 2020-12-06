#include <bits/stdc++.h>

using namespace std;

// priority_queue struct 관련 예시
namespace _11098 {
	struct player {
		int price;
		string name;
		player(int a, string b) {
			price = a;
			name = b;
		}

		bool operator<(const player& b) const {
			return price < b.price;
		}
	};

	int c, n;
	int main() {
		cin >> c;
		while (c--) {
			cin >> n;
			priority_queue<player> players;
			for (int i = 0; i < n; i++) {
				int price;
				string name;
				cin >> price >> name;
				players.push(player(price, name));
			}
			cout << players.top().name << "\n";
		}

		return 0;
	}
}
