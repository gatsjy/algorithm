#include<bits/stdc++.h>

using namespace std;

typedef struct ListNode { // 원형 연결 리스트의 노드 구조 정의
	int data;
	struct ListNode* link;
} listNode;

typedef struct { // 원형 연결 리스트의 헤드 노드 구조 정의
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void) { // 원형 연결 리스트의 헤드 노드 생성
	linkedList_h* H;
	H = (linkedList_h*)malloc(sizeof(linkedList_h));
	H->head = NULL;
	return H;
}

// 원형 리스트 첫 번째 노드 삽입 연산, x값은 100이라고 가정함
void addFirstNode(linkedList_h* H, int x) {
	listNode* tempNode;
	listNode* NewNode;
	NewNode = (listNode*)malloc(sizeof(listNode));
	NewNode->data = x;
	NewNode->link = NULL;
}

// 삽입
void addFirstNode(linkedList_h* H, int x) {

	if (H->head == NULL) { // 현재 리스트가 공백인 경우
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
