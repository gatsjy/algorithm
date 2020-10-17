#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> skill(N + 1);
	
	for (int i = 1; i <= N; i++) {
		cin >> skill[i];
	}

	for (int i = 1; i <= N; i++) {
		int rank = i;
		for (int j = i-1; j >= 1; j--) {
			if (skill[i] > skill[j]) {
				rank--;
			}
		}
		cout << rank << " ";
	}
	return 0;
}