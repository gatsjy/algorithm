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
//	// 1���� 12�� ���̿��� �Ѵ�.
//	if (month >= 1 && month <= 12) {
//		// ������ month�� day���� ū day �� ���Դ����� üũ
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