#include <iostream>
#include <map>

namespace _2556 {
	using namespace std;

	int main() {
		string s;
		cin >> s;
		int num = 0;
		for (int i = 0; i < s.size(); i++) {
			num *= 16;

			if (s[i] >= 'A' && s[i] <= 'F') {
				num += s[i] - 'A' + 10;
			}
			else {
				num += s[i] - '0';
			}
		}
		cout << num;
		return 0;
	}
}
