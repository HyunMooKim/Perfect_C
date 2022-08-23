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
	printf("�߰��� ��� �̸��� �Է��ϰ� enter�� ��������. ����� ctrl z �Է�\n");
	
	//������ ���
	scanf("%s", name);
	new = (node*)malloc(sizeof(node));
	strcpy(new->name, name);
	new->next = NULL;
	recent = new;
	head = new;

	//��� �߰�
	scanf("%s", name);
	getchar();
	while ( !feof(stdin) ) {
		new = (node*)malloc(sizeof(node));
		strcpy(new->name, name);

		//recent�� �Ű��ָ� �� ���� ���� ����.
		recent->next = new;
		new->next = NULL;
		recent = new;
		fgets(name, sizeof(name), stdin); 
		name[strlen(name) - 1] = '\0';
	}

	//���
	printf("���� ���:\n\n");
	recent = head;
	while (recent) {
		printf("%s  ->", recent->name);
		recent = recent->next;
	}
	printf("NULL");

	printf("\n\n���� ���:\n\n");
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