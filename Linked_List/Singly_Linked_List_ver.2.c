
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//문자열 맨앞에 삽입
#pragma warning(disable:4996)
typedef struct Node {
	char* str;
	struct Node* next;

}Node; // 구조체 변수 선언

typedef struct intNode {
	int value;
	struct intNode* next;

}intNode;


void insert_char(char* p);
void lineupint(int a);
void showif(intNode*ptr1);

int main(void) {
	
	int n = 0;
	int count = 0;
	char ch = 0;
	char array[100];
	int num2 = 0;

	while (1) {
		
		printf("\n메뉴 번호 입력하세요.\n");
		(void)scanf("%d",&n);
		switch (n) {
		case 0: printf("프로그램을 종료합니다.\n");
			exit(0);
		case 1:
			printf("입력한 문자열을 단일연결리스트의 제일 앞에 추가해서 출력합니다\n");
			printf("문자를 입력해주세요\n");
			(void)scanf("%s",array);
			insert_char(array);
			break;
		case 2: 
			printf("입력한 숫자를 정렬하여 연결리스트로 표시합니다\n");
			printf("정수를 입력해주세요\n");
			(void)scanf("%d", &num2);
			lineupint(num2);
			break;
		}


	}
}





void insert_char(char* p)
{
	static Node* head = NULL; //함수내부에서 한번만 초기화되고 프로그램종료전까지 그 값이 유지됨,즉, 반복문에 휘말리지않음, 전역변수처럼 사용가능
	Node* Newnode = (Node*)malloc(sizeof(Node));
	char* array = (char*)malloc(strlen(p)+1);//배열길이+1(NULL문자도 포함시켜야 정확히읽음
	if (Newnode == NULL) {

		printf("Newnode 동적할당 실패.\n");
		return;
	}
	else if (array == NULL) {
		printf("array 동적할당 실패.\n");
		free(Newnode);
		return;

	}
	Newnode->next = NULL;
	strcpy(array, p);
	if (head == NULL) {
		head = Newnode;
		Newnode->str = array;
		printf("[%s]\n", Newnode->str);
		return;
	}//헤드가 NULL이면 연결이 아예 안되어있으므로 연결하고 뉴노드 연결 str이 배열 가리키게끔
	
	
	Newnode->next = head;
	head = Newnode;
	Newnode->str = array;
	while (Newnode != NULL) {	
		printf("[%s]\n", Newnode->str);
		Newnode = Newnode->next;

	}
} // 노드 정렬 삽입+문자열 노드 전체 제거 추가바람

void lineupint(int a)//노드 정렬 삽입
{
	static intNode* head = NULL;	
	intNode* Newnode = (intNode*)malloc(sizeof(intNode));
	
	if (Newnode == NULL) {

		printf("동적할당 실패\n");
		return;
	}
	Newnode->next = NULL;
	if (head == NULL) {
		head = Newnode;
		head->value = a;
		showif(head);
		return;
	 }//1.head==NULL
	Newnode->value = a;
	if (Newnode->value <= head->value) {
		Newnode->next = head;
		head = Newnode;
		showif(head);
		return;
	}//2.가장 작은 값 삽입 

	intNode* Curnode = head;
	intNode* prevnode = head;
	while (Curnode->next!=NULL) {
		Curnode = Curnode->next;

		if (Curnode->value >= a) {
			Newnode->next = Curnode;
			prevnode->next = Newnode;
			showif(head);
			return;
		}
		prevnode = prevnode->next;
		showif(head);
	}//3.일반적인 값 삽입
	Curnode->next = Newnode; //4. 가장 큰 값 삽입
	showif(head);

}
void showif(intNode* cur) {
	while (cur) {
		printf("%d", cur->value);
		if (cur->next) printf("=>");
		cur = cur->next;
	}
	printf("\n");
}



