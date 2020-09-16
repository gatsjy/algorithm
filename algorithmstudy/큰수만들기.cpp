#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define INF 2147000000

using namespace std;

vector<int> a;
vector<int> ch;
vector<int> v;
int n = 0;
long long maxv = -INF;
void dfs(int start, int k) {
	if (v.size() == k) {
		long long tmp = 0;
		for (int i = 0; i < v.size(); i++) {
			tmp = tmp * 10 + v[i];
			//cout << v[i] << " ";
		}
		//cout << endl;
		maxv = max(maxv, tmp);
	}
	else {
		for (int i = start; i < a.size(); i++) {
			if (ch[i] == 0) {
				ch[i] = 1;
				v.push_back(a[i]);
				dfs(i + 1, k);
				ch[i] = 0;
				v.pop_back();
			}
		}
	}
}

string solution(string number, int k) {
	for (int i = 0; i < number.size(); i++) {
		a.push_back(number[i] - '0');
	}
	n = a.size();
	ch = vector<int>(n + 1);
	dfs(0, n - k);

	string answer = to_string(maxv);
	return answer;
}