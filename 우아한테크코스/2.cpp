#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

namespace _1 {
	int solution(int n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			string s = to_string(i);

			for (int j = 0; j < s.size(); j++) {
				if (s[j] == '3' || s[j] == '6' || s[j] == '9') {
					cnt++;
				}
			}
		}

		return cnt;
	}

	int main() {
		int number = 14;
		solution(number);
	}
}
