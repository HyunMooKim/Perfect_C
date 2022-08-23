#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//students.txt ���Ͽ� �л����� ������ �߰��ϰ�, �˻��ϰ� ����ϴ� ���α׷�
//�� �����Ҷ����� 1ȸ��. 
void print_menu();
void printscore(FILE* f);
void search(FILE* f, int cnt);
int append(FILE* f, int cnt); 

int main() {
	int choice;
	int cnt = 0;
	FILE* f;

	do {
		print_menu();
		scanf("%d", &choice);
		getchar();
		//�߰� : append ���
		if (choice == 1) {
			if (fopen_s(&f, "students.txt", "a") != 0) {
				printf("������ ������ �ʽ��ϴ�.");
				return -1;
			}
			cnt = append(f, cnt);
		}
		//��� ��� : read ���
		else if (choice == 2) {
			if (fopen_s(&f, "students.txt", "r") != 0) {
				printf("������ ������ �ʽ��ϴ�.");
				return -1;
			}
			printscore(f);
		}
		//��ȣ�� �˻� 
		else if (choice == 3) {
			if (fopen_s(&f, "students.txt", "r") != 0) {
				printf("������ ������ �ʽ��ϴ�.");
				return -1;
			}
			search(f, cnt);
		}
		//���� 
		else if (choice == 4) {
			return 0;
		}
		else {
			printf("�߸��� �Է�\n");
		}

	} while (choice != 4);

	return 0;
}

int append(FILE* f, int cnt) {
    // ctrl + z  �� �Էµɶ����� ��� �߰�
	char line[50];
	int mid;
	int final;
	int quiz;
	printf("�߰��� �л��� �̸� �߰� �⸻ ���� �� �Է��ϼ���\n");
	fgets(line, sizeof(line), stdin);
	while ( !feof(stdin) ) {
		fprintf(f, "%d ", ++cnt);
		fprintf(f,"%s", line);
		fgets(line, sizeof(line), stdin);
	}
	fclose(f);
	return cnt;
}

void search(FILE* f, int cnt) {
	int who;
	int count = 1;
	char line[50];
	printf("������� %d �� �л��� ������ ����ֽ��ϴ�.\n", cnt);
	printf("ã�� �л� ��ȣ�� �Է��ϼ��� >>");
	scanf("%d", &who);

	//���ϴ� ��ȣ�� �л��� ã�� �۾�
	while (count != who) {
		fgets(line, sizeof(line), f);
		count++;
	}
	fgets(line, sizeof(line), f);
	printf("%s", line);
	fclose(f);
	return;
}

void printscore(FILE* f) {
	char line[50];
	int readcnt = fread(line, sizeof(line), 1, f);
	if (readcnt == 0) {
		printf("���� ���� ������ �����ϴ�.");
		return;
	}
	while (!feof(f)) {
		fprintf(stdout, "%s\n", line);
		fread(line, sizeof(line), 1, f);
	}
	fclose(f);
	return;
}

void print_menu() {
	printf("\n\n[1] �л� �߰�\n");
	printf("[2] �л� ��� ���\n");
	printf("[3] �л� �˻�\n");
	printf("[4] ����\n");
	return;
}