#include <bits/stdc++.h>

using namespace std;
namespace _11723 {
	int c, n, bit = 0;
	string s;

	void tentotwo(int n) {
		if (n == 0) {
			cout << "\n";
			return;
		}
		tentotwo(n / 2);
		cout << n % 2;
		return;
	}

	// 1. set으로 풀이 -> 실패
	// 2. bool로 풀이
	// 3. 비트마스킹으로 풀이??
	// 참고 https://donggoolosori.github.io/2020/09/24/boj-11723/
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		//cout << (1 << 1) << "\n"; // 1<<1 -> 2의 1제곱 -> 10
		//tentotwo(1 << 1);
		//cout << (1 << 2) << "\n"; // 1<<2 -> 2의 2제곱 -> 100
		//tentotwo(1 << 2);
		//cout << (1 << 3) << "\n"; // 1<<3 -> 2의 3제곱 -> 1000
		//tentotwo(1 << 3);
		//cout << (1 << 4) << "\n"; // 1<<4 -> 2의 4제곱 -> 10000
		//tentotwo(1 << 4);
		//cout << (1 << 5) << "\n"; // 1<<5 -> 2의 5제곱 -> 100000
		//tentotwo(1 << 5);
		//cout << (1 << 6) << "\n"; // 1<<6 -> 2의 6제곱 -> 1000000
		//tentotwo(1 << 6);
		//cout << (1 << 7) << "\n"; // 1<<7 -> 2의 7제곱 -> 10000000
		//tentotwo(1 << 7);

		cin >> c;

		while (c--) {
			cin >> s;
			if (s == "add") // add
			{
				cin >> n;
				bit |= (1 << n); // or 연산자를 이용
			}
			else if (s[0] == 'c') // check
			{
				cin >> n;
				if (bit & (1 << n)) {
					cout << 1 << "\n";
				}
				else {
					cout << 0 << "\n";
				}
			}
			else if (s[0] == 'r') // remove
			{
				cin >> n;
				bit &= ~(1 << n);
			}
			else if (s == "all") // all
			{
				// 와 이 테크닉 기억해둬야겠다.
				bit = (1 << 21) - 1; // 2의 21제곱 10000000000000000000-1 => 1111111111111111
			}
			else if (s[0] == 'e') // empty
			{
				bit = 0;
			}
			else if (s[0] == 't') // toggle
			{
				// xor 연산 -> 대응하는 두 비크가 다르면 1 같으면 0 반환
				cin >> n;
				bit ^= (1 << n);
			}
		}
		return 0;
	}
}