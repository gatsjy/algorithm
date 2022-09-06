#include <bits/stdc++.h>

using namespace std;

namespace _2309{
	int n;
	vector<int> dwarf;

	void solution() {
		for (int a = 0; a < 9; a++) {
			for (int b = a + 1; b < 9; b++) {
				for (int c = b + 1; c < 9; c++) {
					for (int d = c + 1; d < 9; d++) {
						for (int e = d + 1; e < 9; e++) {
							for (int f = e + 1; f < 9; f++) {
								for (int g = f + 1; g < 9; g++) {
									if (dwarf[a] + dwarf[b] + dwarf[c] + dwarf[d] + dwarf[e] + dwarf[f] + dwarf[g] == 100) {
										printf("%d\n", dwarf[a]);
										printf("%d\n", dwarf[b]);
										printf("%d\n", dwarf[c]);
										printf("%d\n", dwarf[d]);
										printf("%d\n", dwarf[e]);
										printf("%d\n", dwarf[f]);
										printf("%d\n", dwarf[g]);
										return;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int main() {
		for (int i = 0; i < 9; i++) {
			cin >> n;
			dwarf.push_back(n);
		}
		sort(dwarf.begin(), dwarf.end());

		solution();

		return 0;
	}
}