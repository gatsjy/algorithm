#include <bits/stdc++.h>

using namespace std;
namespace _3003 {
	int ch[6] = { 1,1,2,2,2,8 };
	int main() {
		int n;
		for (int i = 0; i < 6; i++) {
			cin >> n;
			cout << ch[i] - n << " ";
		}
		return 0;
	}
}
