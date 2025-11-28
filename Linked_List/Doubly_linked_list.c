#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct Dnode {
	struct Dnode* prev;
	struct Dnode* next;
	int value;
}Dnode;

Dnode*head = NULL;
Dnode*tail = NULL;
void Insert_Node_at_the_front(int a);
void Insert_Node_at_the_rear(int a);
void showif(Dnode* Cur);
int main(void) {
	int n = 0;
	while (1) {
		printf("Select Menu\nNum0:Insert New Node at the head\nNum1:Insert New Node at the tail\n");
		(void)scanf("%d", &n);
		switch (n) {
		case 0:
			printf("Menu 0:Input Num\n");
			(void)scanf("%d", &n);
			Insert_Node_at_the_front(n);
			break;
		case 1:
			printf("Menu 1:Input Num\n");
			(void)scanf("%d", &n);
			Insert_Node_at_the_rear(n);
		}
	  }





	return 0;
}



void Insert_Node_at_the_front(int a)
{
	Dnode* Newnode = (Dnode*)malloc(sizeof(Dnode));
	if (Newnode == NULL) {

		printf("Failed to Dynamic Allocation\n");
		return;
	}
	Newnode->next = NULL;
	Newnode->prev = NULL;
	Newnode->value = a;
	if (head == NULL) {
		head = Newnode;
		tail = Newnode;
		showif(head);
		return;
		
	}
	
	Newnode->next = head;
	head->prev = Newnode;
	head = Newnode;
	showif(head);
	return;
}

void Insert_Node_at_the_rear(int a)
{
	Dnode* Newnode = (Dnode*)malloc(sizeof(Dnode));
	if (Newnode == NULL) {
		printf("Failed to Dynamic allocation\n");
		return;
	}
	Newnode->prev = NULL;
	Newnode->next = NULL;
	Newnode->value = a;
	if (head == NULL) {
		head = Newnode;
		tail = Newnode;
		showif(head);
		return;
		
}
	tail->next = Newnode;
	Newnode->prev = tail;
	tail = Newnode;
	showif(head);
	return;
}

void showif(Dnode* Cur)
{
	while (Cur) {
		printf("[%d]", Cur->value);
		if (Cur->next)printf("<=>");
		Cur = Cur->next;
	}
	printf("\n");
}
//맨앞 노드 삭제,중간 노드삭제, 맨 뒤 노드 삭제 추가 바람

