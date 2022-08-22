#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//2001 ������ random�� �⵵�� �޷��� ����ϴ� ���α׷�
//2001.01.01�� ������ �̸� �������� ����Ѵ�. 
//�ܼ�â���� �����ϰ� �����µ�, �޸����� �ణ �߶Ի���
char *days[7] = { "��","��","ȭ","��","��","��","��" };

void fprintf_calendar(FILE* f, int year);
int get_total_dates(int year);
int get_max_day(int leap, int month);
int isLeap(int year);

int main()
{
	FILE* f;
	char name[30]; 
	int year;

	printf("�⵵�� �Է��ϼ���: ex) 2022\n");
	scanf("%d", &year);

	printf("���� �̸��� �Է��ϼ���: ex) 2022.txt\n");
	scanf("%s", name);

	if (fopen_s(&f, name, "w") != 0) {
		printf("������ ������ �ʽ��ϴ�.");
		return -1;
	}
	
	fprintf_calendar(f, year);
	fclose(f);
	return 0;
}

//���ϰ� �ֿܼ� �޷� ���
void fprintf_calendar(FILE* f, int year) {
	int total;
	int startday;
	int leap;
	int goal_date;
	int monthcnt = 0;
	int totalcnt = 0;
	int max_month;
	total = get_total_dates(year);
	startday = (total +1 ) % 7; //���ۿ��� 2001.01.01 �� ��(1) �̴ϱ� 1 �����ش�.
	
	//���⿡ ���� ��ǥ ����
	leap = isLeap(year);
	if (leap == 1)
		goal_date = 366;
	else
		goal_date = 365;

	while (totalcnt != goal_date) {
		for (int month = 1; month <= 12; month++) {
			printf("         [%d�� %d��]\n", year, month);
			printf("----------------------------\n");
			printf("  ��  ��  ȭ  ��  ��  ��  ��\n");
			
			fprintf(f,"         [%d�� %d��]\n", year, month);
			fprintf(f,"----------------------------\n");
			fprintf(f,"  ��  ��  ȭ  ��  ��  ��  ��\n");

			//���ۿ��ϱ��� ����
			for (int i = 0; i < startday; i++) {
				printf("    ");
				fprintf(f,"     ");
			}
				

			//�� ���� �ִ��ϱ��� ����ϸ� �� 365 or 366�� �����ϸ� �����.
			max_month = get_max_day(leap, month);
			while (monthcnt != max_month){
				monthcnt++;
				totalcnt++;
				
				printf("%4d", monthcnt);
				fprintf(f, "%5d", monthcnt);
				if (  (monthcnt + startday ) % 7 == 0) { //����ϸ��� ����.
					printf("\n");
					fprintf(f,"\n");
				}
				if (totalcnt == goal_date) {
					break; //12���� ä�����ϱ� �˾Ƽ� for�������� ����
				}
			}
			startday = (startday + (monthcnt % 7) ) % 7; //�����ָ� �Ŵ� ���� �� ���� 
			monthcnt = 0;
			printf("\n\n");
			fprintf(f, "\n\n");
		}
	}
	

}
//2001.01.01 ���� �ش� �⵵ �������� �� �ϼ� ���
int get_total_dates(int year) {
	int Leap;
	int total = 0;
	for (int i = 2001; i < year; i++) {
		Leap = isLeap(i);
		if ( Leap == 1) {
			total = total + 366;
		}
		else
			total = total + 365;
	}

	return total;
}
//year�� month ���� ������ ��� 
int get_max_day(int leap, int month) {
	if (leap == 1) {
		if (month == 2) {
			return 29;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			return 30;
		}
		else return 31;
	}
	else {
		if (month == 2) {
			return 28;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			return 30;
		}
		else return 31;
	}
}

//���� �˻� - ������ 1 ��ȯ
int isLeap(int year) {
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}