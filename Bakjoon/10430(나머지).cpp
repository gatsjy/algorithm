#include <bits/stdc++.h>

using namespace std;

namespace _1037 {
	int A, B, C;

	int main() {
		cin >> A >> B >> C;
		cout << (A + B) % C << "\n";
		cout << ((A % C) + (B % C)) % C << "\n";
		cout << (A * B) % C << "\n";
		cout << (((A % C) * (B % C)) % C) % C << "\n";
		return 0;
	}
}
