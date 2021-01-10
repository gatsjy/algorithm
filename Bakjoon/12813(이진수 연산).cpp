#include <bits/stdc++.h>
#include <bitset>

using namespace std;

namespace _12813 {
	int main() {
		bitset<100000> a;
		bitset<100000> b;
		cin >> a >> b;
		cout << (a & b) << "\n";
		cout << (a | b) << "\n";
		cout << (a ^ b) << "\n";
		cout << ~(a) << "\n";
		cout << ~(b) << "\n";
		return 0;
	}
}
