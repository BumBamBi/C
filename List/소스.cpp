#include<stdio.h>
#include<stdlib.h>	//malloc사용
#include<string.h>	//strcpy사용

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode* head;
}LinkedList_h;

LinkedList_h* createNULLList() {
	LinkedList_h* L;
	L = (LinkedList_h*)malloc(sizeof(LinkedList_h));
	L->head = NULL;
	return L;
}

void FirstNode(LinkedList_h* L, char* a) {
	ListNode* NewNode;
	NewNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(NewNode->data, a); 
	NewNode->link = L->head;
	L->head = NewNode;
}

int main()
{
	LinkedList_h* L;
	createNULLList();
}

