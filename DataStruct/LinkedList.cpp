#include<bits/stdc++.h>

using namespace std;

typedef struct ListNode { // ���� ���� ����Ʈ�� ��� ���� ����
	int data;
	struct ListNode* link;
} listNode;

typedef struct { // ���� ���� ����Ʈ�� ��� ��� ���� ����
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void) { // ���� ���� ����Ʈ�� ��� ��� ����
	linkedList_h* H;
	H = (linkedList_h*)malloc(sizeof(linkedList_h));
	H->head = NULL;
	return H;
}

int main() {

}