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

// ���� ����Ʈ ù ��° ��� ���� ����, x���� 100�̶�� ������
void addFirstNode(linkedList_h* H, int x) {
	listNode* tempNode;
	listNode* NewNode;
	NewNode = (listNode*)malloc(sizeof(listNode));
	NewNode->data = x;
	NewNode->link = NULL;
}

// ����
void addFirstNode(linkedList_h* H, int x) {

	if (H->head == NULL) { // ���� ����Ʈ�� ������ ���
		H->head = NewNode;
		NewNode->link = NewNode;
		return;
	}

	tempNode = H->head;
	while (tempNode->link != H->head) {
		tempNode = tempNode->link;
	}
	NewNode->link = tempNode->link;
	tempNode->link = NewNode;
	H->head = NewNode;
}
