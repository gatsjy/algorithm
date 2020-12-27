#include <bits/stdc++.h>

using namespace std;
namespace _1072 {
	// 이분검색을 사용하는이유가 무엇일까?
// 1~100을 검색하한다고 생각하면 특정 수를 찾는 알고리즘은 
// 하나씩 검색하면 n / 하지만 반씩 줄어들어가면 log2n
	long long x, y;
	long long res = 2147000000;
	int main() {
		cin >> x >> y;
		long long lt = 1;
		long long rt = 2000000001;

		int wrate = y * 100 / x;

		if (wrate >= 99) {
			cout << -1;
		}
		else {
			// 이분 검색 시작..
			while (lt <= rt) {
				long long mid = (lt + rt) / 2;
				// twrate == temp win rate
				int twrate = (y + mid) * 100 / (x + mid);
				if (twrate > wrate) {
					rt = mid - 1;
				}
				else {
					lt = mid + 1;
				}
			}
			cout << lt;
		}
		return 0;
	}
}