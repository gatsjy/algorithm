#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

namespace _메뉴리뉴얼 {
	set<char> ss;
	vector<char> a;
	vector<char> v;
	int ch[26];
	vector<string> answer;

	int r[21];
	map<int, vector<string>> mm;

	// 해당 문자열에 포함되는 문자열인지 파악
	bool isOverlap(string target, vector<char> menus) {
		int dch[26] = { 0, };
		if (target.size() < menus.size()) return false;
		for (int i = 0; i < target.size(); i++) {
			dch[target[i] - 'A']++;
		}
		for (int i = 0; i < menus.size(); i++) {
			dch[menus[i] - 'A']++;
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			if (dch[i] > 1) cnt++;
		}
		if (cnt == menus.size()) return true;
		return false;
	}

	// 해당 조합 메뉴가 2번이상 체크되었는지 확인합니다.
	void isSelectedMenu(vector<string>& orders, vector<char> menus) {
		int cnt = 0;
		for (int i = 0; i < orders.size(); i++) {
			string s = orders[i];
			sort(s.begin(), s.end());
			if (isOverlap(s, menus)) {
				cnt++;
			}
		}
		if (cnt > 1) {
			string s;
			for (int i = 0; i < menus.size(); i++) {
				s += menus[i];
			}
			if (r[menus.size()] == 0) {
				r[menus.size()] = cnt;
				mm[menus.size()].push_back(s);
			}
			else if (r[menus.size()] < cnt) {
				r[menus.size()] = cnt;
				mm[menus.size()].clear();
				mm[menus.size()].push_back(s);
			}
			else if (r[menus.size()] == cnt) {
				mm[menus.size()].push_back(s);
			}
		}
	}

	void dfs(vector<string>& orders, int size, int idx) {
		if (v.size() == size) {
			//for (int i = 0; i < v.size(); i++) {
			//	cout << v[i] << " ";
			//}
			//cout << "\n";
			isSelectedMenu(orders, v);
		}
		else {
			for (int i = idx; i < a.size(); i++) {
				v.push_back(a[i]);
				ch[a[i] - 'A'] = 1;
				dfs(orders, size, i + 1);
				v.pop_back();
				ch[a[i] - 'A'] = 0;
				;
			}
		}
	}
	vector<string> solution(vector<string> orders, vector<int> course) {

		for (int i = 0; i < orders.size(); i++) {
			for (int j = 0; j < orders[i].size(); j++) {
				ch[orders[i][j] - 'A']++;
			}
		}

		for (int i = 0; i < 26; i++) {
			if (ch[i] > 1) {
				a.push_back(i + 'A');
			}
		}
		for (int i = 0; i < course.size(); i++) {
			v.clear();
			memset(ch, 0, sizeof(ch));
			dfs(orders, course[i], 0);
		}

		for (int i = 0; i < 21; i++) {
			if (r[i] > 0) {
				for (int j = 0; j < mm[i].size(); j++) {
					answer.push_back(mm[i][j]);
				}
			}
		}
		sort(answer.begin(), answer.end());

		return answer;
	}

	int main() {
		//vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
		//vector<string> orders = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
		vector<string> orders = { "XYZ", "XWY", "WXA" };
		//vector<int> course = {2,3,4};
		//vector<int> course = {2,3,5};
		vector<int> course = { 2,3,4 };

		solution(orders, course);
		return 0;
	}
}
