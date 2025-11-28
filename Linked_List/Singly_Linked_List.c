
#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {

	int value;
	struct Node* next;

}Node;

int deletenode = 0;

Node* head = NULL;
void insert_node_front(int a);
void insert_node_rear(int a);
void delete_node(int a);
void display(void);
void free_memory(void);


int main(void) {
	
	int menu = 0;
	int newvalue = 0;
	while (1) {
		
		printf("\n####연결 리스트 추적####\n");
		printf("1번:연결 노드 제일 앞에 추가(입력값:노드의 value)\n");
		printf("2번:연결 노드 값 순회하며 보여줌\n");
		printf("3번:동적 메모리 해제\n");
		printf("4번:노드 제일 뒤에 추가\n");
		printf("5번:선택 노드 삭제\n");
		printf("0번:종료\n");


		scanf_s("%d", &menu);
		while (menu<0||menu>5) {
			printf("메뉴 번호를 다시 입력하세요\n");
			scanf_s("%d", &menu);
			if (menu<5 && menu>=0)
			{
				break;
			}
		}

		switch (menu) {
		case 1:
			printf("신규 노드 맨 앞에 삽입할 value값을 입력하세요.\n");
			scanf_s("%d", &newvalue);
			insert_node_front(newvalue);
			system("cls");
			break;


		case 2:
			display();
			break;


		case 3:
			printf("동적메모리 해제\n");
			free_memory();
			break;
        
        
		case 4:
			printf("신규 노드 맨 뒤에 삽입할 value값을 입력하세요.\n");
			scanf_s("%d", &newvalue);
			insert_node_rear(newvalue);
			system("cls");
			break;

		case 5:
			printf("삭제할 n번째 노드를 입력하세요.\n");
			scanf_s("%d", &deletenode);
			delete_node(deletenode);
			break;

  		case 0:
			
			printf("프로그램을 종료합니다.");
			exit(0);



		}

		
	}
	return 0;
}

void insert_node_front(int a)
{
	
	Node* NewNode = (Node*)malloc(sizeof(Node)); 
	if (NewNode == NULL) {
		printf("동적할당실패");
		return;
	}
	NewNode->next = NULL;
	
	NewNode->value = a;
	if (head == NULL) {
		head = NewNode;
		return; 	}
	NewNode->next = head;
	head = NewNode;
}

void insert_node_rear(int a)
{
	Node* Newnode = (Node*)malloc(sizeof(Node));
	if (Newnode == NULL) {
		printf("동적할당실패.\n");
		return;
	}
	Newnode->value = a;
	Newnode->next = NULL;
	Node* Curnode = head;
	if (head == NULL) {
		head = Newnode;
		return;
	}
	
	
	while (Curnode->next!=NULL) {
		Curnode = Curnode->next;
	}
	Curnode->next = Newnode;


}


void delete_node(int a)
{
	if (a <= 0) {
		printf("잘못된 위치: 1 이상의 값을 입력하세요.\n");
		return;
	}
	if (head == NULL) {
		printf("삭제할 노드가 없습니다.\n");
		return;
	}

	
	if (a == 1) {
		Node* to_delete = head;
		head = head->next;
		free(to_delete);
		printf("삭제 완료.\n");
		return;
	}

	
	Node* prevnode = head;
	Node* delnode = head->next;
	int  count = 2;  

	
	while (delnode != NULL && count < a) {
		prevnode = delnode;
		delnode = delnode->next;
		count++;
	}

	
	if (delnode == NULL) {
		printf("%d번째 노드는 존재하지 않습니다.\n", a);
		return;
	}

	
	prevnode->next = delnode->next;
	free(delnode);
	printf("%d번째 노드 삭제 완료.\n", a);
}

	
void display(void)
{
	Node* Curnode;

	if (head == NULL) {

		printf("출력할 노드가 없습니다.노드 생성부터 하세요.\n");
		return;
	}
	Curnode = head;
	printf("%d", Curnode->value);
	
	while (Curnode->next != NULL) {
		Curnode = Curnode->next;
		printf(" => %d", Curnode->value);
		
	}
	printf("=> NULL값");
	
}

void free_memory(void)
{
	Node* Curnode=head;
	
	while (Curnode->next != NULL) {
		Node*next_add= Curnode->next;
		free(Curnode);
		Curnode = next_add;
	}
	free(Curnode);
	head = NULL;
}





