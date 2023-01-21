//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n;
//int a[101];
//int b[101];
//int main() {
//	for (int i = 0; i < 10; i++) {
//		cin >> a[i];
//	}
//	for (int i = 0; i < 10; i++) {
//		cin >> b[i];
//	}
//
//	int a_score = 0;
//	int b_score = 0;
//	string lastwin = "D";
//	for (int i = 0; i < 10; i++) {
//		if (a[i] > b[i]) {
//			a_score += 3;
//			lastwin = "A";
//		}
//		if (a[i] < b[i]) {
//			b_score += 3;
//			lastwin = "B";
//		}
//		if (a[i] == b[i]) {
//			a_score += 1;
//			b_score += 1;
//		}
//	}
//
//	cout << a_score << " " << b_score << "\n";
//
//	if (a_score > b_score) {
//		cout << "A";
//	}
//	else if (a_score < b_score) {
//		cout << "B";
//	}
//	else {
//		cout << lastwin;
//	}
//
//	return 0;
//}