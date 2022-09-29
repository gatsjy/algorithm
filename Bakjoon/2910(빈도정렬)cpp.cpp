#include <bits/stdc++.h>

using namespace std;

// 이거 다시 내힘을 풀어보기!!
int n, c, a[1001];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) { // 갯수가 같다면 
		return mp_first[a.second] < mp_first[b.second]; // 먼저 들어온 것 (idx가 작은것을 세팅) 
	}
	return a.first > b.first; // 보통은 더 많은 개수를 가진것을 비교
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++; // 갯수를 세는 map
		if (mp_first[a[i]] == 0) mp_first[a[i]] = i + 1; // 한번도 들어간 적이 없다면 푸쉬
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