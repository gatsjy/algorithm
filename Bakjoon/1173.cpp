#include <bits/stdc++.h>

using namespace std;

namespace _1293 {
	int calScore(string s, string on) {
		string tmp = s + on;
		int L = 0;
		int O = 0;
		int V = 0;
		int E = 0;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == 'L') {
				L++;
			}
			else if (tmp[i] == 'O') {
				O++;
			}
			else if (tmp[i] == 'V') {
				V++;
			}
			else if (tmp[i] == 'E') {
				E++;
			}
		}
		return ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
	}

	struct woman {
		string name;
		int score;

		woman(string a, int b) {
			name = a;
			score = b;
		}
		bool operator<(const woman& b) const {
			if (score == b.score) {
				return name > b.name;
			}
			return score < b.score;
		}
	};
	int main() {
		priority_queue<woman> pq;
		string on, s;
		int n;
		cin >> on;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s;
			pq.push(woman(s, calScore(s, on)));
		}
		cout << pq.top().name;
		return 0;
	}
}
