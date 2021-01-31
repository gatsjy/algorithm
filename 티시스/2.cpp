//#include <iostream>
//#include<string>
//#include<stdio.h>
//#include<string.h>
//
//using namespace std;
//
////심볼('!', '@', '#', '$')
//bool isSymbol(char c) {
//	if (!(c == '!' || c == '@' || c == '#' || c == '$')) {
//		return false;
//	}
//	return true;
//}
//
//bool isIdOkay(string s) {
//	// 1. 3글자 이상, 20글자 이하의 문자열
//	if (s.size() >= 3 && s.size() <= 20) {
//		for (int i = 0; i < s.size(); i++) {
//			// 2. 알파벳 소문자와 숫자만을 사용해야한다.
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
//// 알파벳 대/소문자, 숫자, 특수기호를 사용할 수 있다.
//bool isPwdOkay(string s) {
//	int wordCnt = 0; // 단어
//	int numCnt = 0; // 숫자
//	int symCnt = 0; // 심볼('!', '@','#','$')
//
//	// 1. 8글자 이상, 20글자 이하
//	if (s.size() >= 8 && s.size() <= 20) {
//		for (int i = 0; i < s.size(); i++) {
//
//			// 2. 알파벳 대/소문자, 숫자, 특수기호(!,@,#,$)를 사용할 수 있다.
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
//	// 알파벳, 숫자, 특수기호는 각각 하나 이상은 반드시 사용되어야 한다.
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
//	// 1. 아이디 체크로직
//	if (isIdOkay(id)) {
//		// 2. 비밀번호 체크로직
//		if (isPwdOkay(pw1)) {
//			// 3. 비밀번호 체크로직 && pw1와 pw2 같은 문자열인지 체크
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