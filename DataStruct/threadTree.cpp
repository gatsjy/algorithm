#include <bits/stdc++.h>

using namespace std;

struct TNode {
	int info;
	TNode left;
	TNode right;
	TNode right_thread;
	TNode left_thread;
};

// 포인터 필드의 추가 : 스레드를 저장하는 포인터를 추가하는 것
// 왼쪽 스레드 포인터, 왼쪽 자식 포인터, 데이터, 오른쪽 자식 포인터, 오른쪽 스레드 포인터 필드로 노드 구조를 정의함

void inorder(struct TNode* firstin) {
	struct TNode* p;
	p = firstin;
	while (p != NULL) {
		printf("%d", p->info);
		p = p->right_thread;
	}
}
int main() {

}