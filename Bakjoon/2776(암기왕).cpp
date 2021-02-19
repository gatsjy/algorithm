#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c, n, m;
vector<int> note;
vector<int> q;

bool binary_search(int target) {
	int lt = 0;
	int rt = note.size() - 1;
	int res = -1;
	int mid = 0;
	while (lt <= rt) {
		mid = (lt + rt) / 2;
		if (note[mid] <= target) {
			if (target == note[mid]) {
				return true;
			}
			lt = mid + 1;
		}
		else {
			rt = mid - 1;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c;
	while (c--) {
		note.clear();
		q.clear();
		cin >> n;
		int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			note.push_back(a);
		}
		sort(note.begin(), note.end());
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> a;
			q.push_back(a);
		}
		for (int i = 0; i < m; i++) {
			if (binary_search(q[i])) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
	}
	return 0;
}