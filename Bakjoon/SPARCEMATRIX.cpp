#include <bits/stdc++.h>

using namespace std;

#define max_value 101

typedef struct {
	int row;
	int col;
	int value;
} element;


typedef struct zipMatrix {
	element data[max_value];
	int rows; // 행의 개수
	int cols; // 열의 개수
	int terms; // 항의 개수
} SparseMatrix;

int main() {
	int a[6][6] = { {1,0,0,0,0,0},{4,5,0,0,0,0},{0,0,0,0,0,8},{9,0,0,0,0,0},{0,12,0,0,0,0},{0,0,0,0,0,15} };
	cout << sizeof(a) << "\n";

	zipMatrix m = {
	{{0,0,1},{1,0,4},{1,1,5},{2,5,8},{3,0,9},{5,1,12},{5,5,15}},
	6, // 행
	6, // 열
	7 // 압축하는 숫자의 개수
	};

	int b[7][3] = { {0,0,1},{1,0,4},{1,1,5},{2,5,8},{3,0,9},{5,1,12},{5,5,15} };

	cout << sizeof(b) << "\n";
	return 0;
}