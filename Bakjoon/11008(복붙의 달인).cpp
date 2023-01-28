//#include <bits/stdc++.h>
//
//using namespace std;
//
//int c;
//string s, p;
//
//int splitString(string s, string p) {
//	int idx = 0;
//	string tmp = s;
//	int cnt = 0;
//	while (tmp.find(p) != string::npos) {
//		idx = tmp.find(p);
//		cnt += idx + 1;
//		tmp = tmp.substr(idx+p.size());
//	}
//	
//	return cnt+tmp.size();
//}
//int main() {
//	cin >> c;
//	while (c--) {
//		cin >> s;
//		cin >> p;
//		cout << splitString(s, p) << "\n";
//	}
//	return 0;
//}