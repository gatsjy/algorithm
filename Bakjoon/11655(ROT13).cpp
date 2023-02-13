//#include <bits/stdc++.h>
//
//using namespace std;
//
//namespace _11655 {
//	string s, res;
//	int main() {
//		getline(cin, s);
//		for (int i = 0; i < s.size(); i++) {
//			// 회전도 구현해줘야 한다.
//			// 'A' = 65 'Z' = 90
//			// 'a' = 97 'z' = 122
//
//			// 소문자 부분
//			if (s[i] >= 'a' && s[i] <= 'z') {
//				if (s[i] + 13 > 122) {
//					res += s[i] - 13;
//				}
//				else {
//					res += s[i] + 13;
//				}
//			}
//			// 대문자 부분
//			else if (s[i] >= 'A' && s[i] <= 'Z') {
//				if (s[i] + 13 > 90) {
//					res += s[i] - 13;
//				}
//				else {
//					res += s[i] + 13;
//				}
//			}
//			else {
//				res += s[i];
//			}
//		}
//
//		cout << res;
//
//		return 0;
//	}
//}