#include <bits/stdc++.h>

using namespace std;

struct TNode {
	int info;
	TNode left;
	TNode right;
	TNode right_thread;
	TNode left_thread;
};

// ������ �ʵ��� �߰� : �����带 �����ϴ� �����͸� �߰��ϴ� ��
// ���� ������ ������, ���� �ڽ� ������, ������, ������ �ڽ� ������, ������ ������ ������ �ʵ�� ��� ������ ������

void inorder(struct TNode* firstin) {
	struct TNode* p;
	p = firstin;
	while (p != NULL) {
		printf("%d", p->info);
		p = p->right_thread;
	}
}

void Preorder(struct TFNode* root) {
	struct TFNode* p;
	p = root;
	while (p != null) {
		printf("%d", p->info);
		p = p->left;
	}
}
int main() {

}