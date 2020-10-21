#include <bits/stdc++.h>

using namespace std;

namespace _40 {

int main() {
	int p1 = 0, p2 = 0;

	int s;
	cin >> s;
	vector<int> a1(s);
	for (int i = 0; i < s; i++) {
		cin >> a1[i];
	}
	cin >> s;
	vector<int> a2(s);
	for (int i = 0; i < s; i++) {
		cin >> a2[i];
	}

	// 투포인트 알고리즘으로 교집합 구하기
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());

	vector<int> ans;
	while(p1 < a1.size() && p2 < a2.size()){
		if (a1[p1] == a2[p2]) {
			ans.push_back(a1[p1]);
			p1++;
			p2++;
		}
		else {
			if (a1[p1] > a2[p2]) {
				p2++;
			}
			else if (a1[p1] < a2[p2]) {
				p1++;
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
	}
}