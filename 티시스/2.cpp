//#include <iostream>
//#include<string>
//#include<stdio.h>
//#include<string.h>
//
//using namespace std;
//
////�ɺ�('!', '@', '#', '$')
//bool isSymbol(char c) {
//	if (!(c == '!' || c == '@' || c == '#' || c == '$')) {
//		return false;
//	}
//	return true;
//}
//
//bool isIdOkay(string s) {
//	// 1. 3���� �̻�, 20���� ������ ���ڿ�
//	if (s.size() >= 3 && s.size() <= 20) {
//		for (int i = 0; i < s.size(); i++) {
//			// 2. ���ĺ� �ҹ��ڿ� ���ڸ��� ����ؾ��Ѵ�.
//			if (!(islower(s[i]) || isdigit(s[i]))) {
//				return false;
//			}
//		}
//	}
//	else
//	{
//		return false;
//	}
//	return true;
//}
//
//// ���ĺ� ��/�ҹ���, ����, Ư����ȣ�� ����� �� �ִ�.
//bool isPwdOkay(string s) {
//	int wordCnt = 0; // �ܾ�
//	int numCnt = 0; // ����
//	int symCnt = 0; // �ɺ�('!', '@','#','$')
//
//	// 1. 8���� �̻�, 20���� ����
//	if (s.size() >= 8 && s.size() <= 20) {
//		for (int i = 0; i < s.size(); i++) {
//
//			// 2. ���ĺ� ��/�ҹ���, ����, Ư����ȣ(!,@,#,$)�� ����� �� �ִ�.
//			if (!(isdigit(s[i])
//				|| islower(s[i])
//				|| isupper(s[i])
//				|| isSymbol(s[i])))
//			{
//				return false;
//			}
//			else {
//				if (isdigit(s[i])) numCnt++;
//				if (islower(s[i]) || isupper(s[i])) wordCnt++;
//				if (isSymbol(s[i])) symCnt++;
//			}
//		}
//	}
//	else
//	{
//		return false;
//	}
//
//	// ���ĺ�, ����, Ư����ȣ�� ���� �ϳ� �̻��� �ݵ�� ���Ǿ�� �Ѵ�.
//	if (numCnt > 0 && wordCnt > 0 && symCnt > 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	string id;
//	string pw1;
//	string pw2;
//	cin >> id >> pw1 >> pw2;
//
//	if (id.size() > 100) return 0;
//	if (pw1.size() > 100) return 0;
//	if (pw2.size() > 100) return 0;
//
//	// 1. ���̵� üũ����
//	if (isIdOkay(id)) {
//		// 2. ��й�ȣ üũ����
//		if (isPwdOkay(pw1)) {
//			// 3. ��й�ȣ üũ���� && pw1�� pw2 ���� ���ڿ����� üũ
//			if (isPwdOkay(pw2) && pw1 == pw2) {
//				cout << "pass";
//				return 0;
//			}
//			else {
//				cout << "fail";
//				return 0;
//			}
//		}
//		else {
//			cout << "fail";
//			return 0;
//		}
//	}
//	else
//	{
//		cout << "fail";
//		return 0;
//	}
//
//	cout << "fail" << endl;
//	return 0;
//}