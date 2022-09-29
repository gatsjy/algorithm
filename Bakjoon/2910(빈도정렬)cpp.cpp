#include <bits/stdc++.h>

using namespace std;

// �̰� �ٽ� ������ Ǯ���!!
int n, c, a[1001];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) { // ������ ���ٸ� 
		return mp_first[a.second] < mp_first[b.second]; // ���� ���� �� (idx�� �������� ����) 
	}
	return a.first > b.first; // ������ �� ���� ������ �������� ��
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++; // ������ ���� map
		if (mp_first[a[i]] == 0) mp_first[a[i]] = i + 1; // �ѹ��� �� ���� ���ٸ� Ǫ��
	}
	for (auto it : mp) {
		v.push_back({ it.second, it.first });
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].first; j++) {
			cout << v[i].second << " ";
		}
	}
	return 0;
}