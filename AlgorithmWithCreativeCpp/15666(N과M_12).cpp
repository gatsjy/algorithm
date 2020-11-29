#include <bits/stdc++.h>

using namespace std;

namespace _15666 {
	// 하나도 허투로 쓰는 코드가 없도록 코딩하려고 노력하자
	int N, M;

	vector<int> v;
	int ch[8];

	void dfs(int idx, int start, int level) {
		if (level == M) {
			for (int i = 0; i < level; i++) {
				cout << ch[i] << " ";
			}
			cout << "\n";
		}
		else {
			for (int i = start; i < v.size(); i++) {
				ch[level] = v[i];
				dfs(idx + 1, i, level + 1);
			}
		}
	}
	int main() {
		cin >> N >> M;
		map<int, int> m;
		// 중복되는 수열을 여러번 출력 못하게 한다는 말이 무엇일까?
		// 한번 출력되고 나면 그것이 출력되었는지 아닌지를 알아야 한다는 말일까? -> 그렇다면 그것을 어떻게 해결하지?
		// 넣을 때 중복을 체크해서 넣으면 되는 거 아닐까?
		int input;
		for (int i = 0; i < N; i++) {
			cin >> input;
			m[input]++;
			if (m[input] == 1) {
				v.push_back(input);
			}
		}
		sort(v.begin(), v.end());
		dfs(0, 0, 0);
		return 0;
	}
}
