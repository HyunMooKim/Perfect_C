#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//students.txt 파일에 학생들의 정보를 추가하고, 검색하고 출력하는 프로그램
//단 students.txt 파일을 미리 같은 폴더 안에 만들어 두어야 하며, 실행할때마다 1회성. 
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
		//추가 : append 모드
		if (choice == 1) {
			if (fopen_s(&f, "students.txt", "a") != 0) {
				printf("파일이 열리지 않습니다.");
				return -1;
			}
			cnt = append(f, cnt);
		}
		//목록 출력 : read 모드
		else if (choice == 2) {
			if (fopen_s(&f, "students.txt", "r") != 0) {
				printf("파일이 열리지 않습니다.");
				return -1;
			}
			printscore(f);
		}
		//번호로 검색 
		else if (choice == 3) {
			if (fopen_s(&f, "students.txt", "r") != 0) {
				printf("파일이 열리지 않습니다.");
				return -1;
			}
			search(f, cnt);
		}
		//종료 
		else if (choice == 4) {
			return 0;
		}
		else {
			printf("잘못된 입력\n");
		}

	} while (choice != 4);

	return 0;
}

int append(FILE* f, int cnt) {
    // ctrl + z  가 입력될때까지 계속 추가
	char line[50];
	int mid;
	int final;
	int quiz;
	printf("추가할 학생의 이름 중간 기말 퀴즈 를 입력하세요\n");
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
	printf("현재까지 %d 번 학생의 정보가 담겨있습니다.\n", cnt);
	printf("찾을 학생 번호를 입력하세요 >>");
	scanf("%d", &who);

	//원하는 번호의 학생을 찾는 작업
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
		printf("현재 성적 정보가 없습니다.");
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
	printf("\n\n[1] 학생 추가\n");
	printf("[2] 학생 목록 출력\n");
	printf("[3] 학생 검색\n");
	printf("[4] 종료\n");
	return;
}
