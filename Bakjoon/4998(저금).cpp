//#include<bits/stdc++.h>
//
//using namespace std;
//
//double n, b,m;
//int main() {
//
//	while (1) {
//		try{
//			cin >> n >> b >> m;
//			if (cin.eof() == true) break; // 출력 전부 받았을 때 처리하는 것까지 넣어줘야 한다.
//			double res = n * (1 + b / 100);
//			int cnt = 1;
//			while (1) {
//				if (res <= m) {
//					cnt++;
//					res *= (1 + b / 100);
//				}
//				else {
//					break;
//				}
//			}
//			cout << cnt << "\n";
//		}
//		catch (int exception) {}
//	}
//	return 0;
//}