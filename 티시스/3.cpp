//#include <iostream>
//#include <string>
//using namespace std;
//
//int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//string dayOfWeek[] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
//
//int month, day;
//int main() {
//	cin >> month >> day;
//	// 1월과 12월 사이여야 한다.
//	if (month >= 1 && month <= 12) {
//		// 정해진 month의 day보다 큰 day 값 들어왔는지를 체크
//		if (days[month] >= day) {
//			int sum = 0;
//			for (int i = 1; i < month; i++) {
//				sum += days[i - 1];
//			}
//			sum += day;
//
//			cout << dayOfWeek[sum % 7];
//			return 0;
//		}
//		else
//		{
//			cout << "ERROR";
//			return 0;
//		}
//	}
//	else {
//		cout << "ERROR";
//		return 0;
//	}
//	cout << "ERROR";
//	return 0;
//}