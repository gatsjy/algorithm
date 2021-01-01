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

	// 1. set���� Ǯ�� -> ����
	// 2. bool�� Ǯ��
	// 3. ��Ʈ����ŷ���� Ǯ��??
	// ���� https://donggoolosori.github.io/2020/09/24/boj-11723/
	int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);

		//cout << (1 << 1) << "\n"; // 1<<1 -> 2�� 1���� -> 10
		//tentotwo(1 << 1);
		//cout << (1 << 2) << "\n"; // 1<<2 -> 2�� 2���� -> 100
		//tentotwo(1 << 2);
		//cout << (1 << 3) << "\n"; // 1<<3 -> 2�� 3���� -> 1000
		//tentotwo(1 << 3);
		//cout << (1 << 4) << "\n"; // 1<<4 -> 2�� 4���� -> 10000
		//tentotwo(1 << 4);
		//cout << (1 << 5) << "\n"; // 1<<5 -> 2�� 5���� -> 100000
		//tentotwo(1 << 5);
		//cout << (1 << 6) << "\n"; // 1<<6 -> 2�� 6���� -> 1000000
		//tentotwo(1 << 6);
		//cout << (1 << 7) << "\n"; // 1<<7 -> 2�� 7���� -> 10000000
		//tentotwo(1 << 7);

		cin >> c;

		while (c--) {
			cin >> s;
			if (s == "add") // add
			{
				cin >> n;
				bit |= (1 << n); // or �����ڸ� �̿�
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
				// �� �� ��ũ�� ����ص־߰ڴ�.
				bit = (1 << 21) - 1; // 2�� 21���� 10000000000000000000-1 => 1111111111111111
			}
			else if (s[0] == 'e') // empty
			{
				bit = 0;
			}
			else if (s[0] == 't') // toggle
			{
				// xor ���� -> �����ϴ� �� ��ũ�� �ٸ��� 1 ������ 0 ��ȯ
				cin >> n;
				bit ^= (1 << n);
			}
		}
		return 0;
	}
}