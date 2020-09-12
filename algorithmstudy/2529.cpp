#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

#define INF 2147000000;

vector<int> v;
int ch[10] = { 0, };
vector<char> c;
int n;

long Max = -INF;
string Maxs = "";
long Min = INF;
string Mins = "";

bool IsCheck(vector<int> v, vector<char> c) {
	for (int i = 0; i < c.size(); i++) {
		if (c[i] == '>') {
			if (!(v[i] > v[i + 1])) {
				return false;
			}
		}
		else if (c[i] == '<') {
			if (!(v[i] < v[i + 1])) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int idx) {
	if (v.size() == n) {
		if (IsCheck(v, c)) {
			string outputs = "";
			for (int i = 0; i < n; i++) {
				//cout << v[i] << " ";
				outputs += v[i] + '0';
			}
			if (Min > stoll(outputs)) {
				Min = stoll(outputs);
				Mins = outputs;
			}
			if (Max < stoll(outputs)) {
				Max = stoll(outputs);
				Maxs = outputs;
			}
			//cout << endl;
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (ch[i] == 0) {
				ch[i] = 1;
				v.push_back(i);
				dfs(i);
				ch[i] = 0;
				v.pop_back();
			}
		}
	}
}
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	c = vector<char>(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	n = n + 1;

	dfs(0);
	
	cout << Maxs << endl;
	cout << Mins;
	return 0;
}