#include <bits/stdc++.h>

using namespace std;

namespace _1629 {
	long long A, B, C;

	long long pow(int A, int B, int C)
	{
		if (B == 1) {
			return A;
		}
		else {
			long long tmp = pow(A, B / 2, C);
			if (B % 2) {
				return ((tmp * tmp) % C * A) % C;
			}
			else {
				return (tmp * tmp) % C;
			}
		}
	}
	int main() {
		cin >> A >> B >> C;
		cout << pow(A % C, B, C);
		return 0;
	}
}
