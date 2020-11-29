#include <bits/stdc++.h>

using namespace std;

namespace _15666 {
	// �ϳ��� ������ ���� �ڵ尡 ������ �ڵ��Ϸ��� �������
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
		// �ߺ��Ǵ� ������ ������ ��� ���ϰ� �Ѵٴ� ���� �����ϱ�?
		// �ѹ� ��µǰ� ���� �װ��� ��µǾ����� �ƴ����� �˾ƾ� �Ѵٴ� ���ϱ�? -> �׷��ٸ� �װ��� ��� �ذ�����?
		// ���� �� �ߺ��� üũ�ؼ� ������ �Ǵ� �� �ƴұ�?
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
