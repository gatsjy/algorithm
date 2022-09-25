//string add(string x, string y) {
//	int num = 0;
//	int carry = 0;
//	string res;
//
//	reverse(x.begin(), x.end());
//	reverse(y.begin(), y.end());
//
//	while (x.length() < y.length()) {
//		x += '0';
//	}
//	while (x.length() > y.length()) {
//		y += '0';
//	}
//
//	for (int i = 0; i < x.length(); i++) {
//		num = (x[i] - '0' + y[i] - '0' + carry) % 10;
//		res += to_string(num);
//		carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
//	}
//	if (carry != 0) {
//		res += to_string(carry); // 한번 뒤집었으므로 carry가 넘치면 한자리를 추가해야 한다.
//	}
//	reverse(res.begin(), res.end());
//	return res;
//}