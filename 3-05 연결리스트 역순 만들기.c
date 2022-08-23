#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char name[20];
	struct node* next;
}node;

node* reverse(node* head);

int main() {
	char name[20];
	node* head;
	node* new;
	node* recent;
	printf("추가할 노드 이름을 입력하고 enter를 누르세요. 종료는 ctrl z 입력\n");
	
	//최초의 노드
	scanf("%s", name);
	new = (node*)malloc(sizeof(node));
	strcpy(new->name, name);
	new->next = NULL;
	recent = new;
	head = new;

	//계속 추가
	scanf("%s", name);
	getchar();
	while ( !feof(stdin) ) {
		new = (node*)malloc(sizeof(node));
		strcpy(new->name, name);

		//recent를 옮겨주며 그 전의 노드와 연결.
		recent->next = new;
		new->next = NULL;
		recent = new;
		fgets(name, sizeof(name), stdin); 
		name[strlen(name) - 1] = '\0';
	}

	//출력
	printf("정순 출력:\n\n");
	recent = head;
	while (recent) {
		printf("%s  ->", recent->name);
		recent = recent->next;
	}
	printf("NULL");

	printf("\n\n역순 출력:\n\n");
	head = reverse(head);
	recent = head;
	while (recent) {
		printf("%s  ->", recent->name);
		recent = recent->next;
	}
	printf("NULL");
	return 0;
}

node* reverse(node* head) {
	node* p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	return q;
}