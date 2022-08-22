#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//2001 이후의 random한 년도의 달력을 출력하는 프로그램
//2001.01.01은 월요일 이를 기준으로 계산한다. 
//콘솔창에는 깨끗하게 나오는데, 메모장은 약간 삐뚤빼뚤
char *days[7] = { "일","월","화","수","목","금","토" };

void fprintf_calendar(FILE* f, int year);
int get_total_dates(int year);
int get_max_day(int leap, int month);
int isLeap(int year);

int main()
{
	FILE* f;
	char name[30]; 
	int year;

	printf("년도를 입력하세요: ex) 2022\n");
	scanf("%d", &year);

	printf("파일 이름을 입력하세요: ex) 2022.txt\n");
	scanf("%s", name);

	if (fopen_s(&f, name, "w") != 0) {
		printf("파일이 열리지 않습니다.");
		return -1;
	}
	
	fprintf_calendar(f, year);
	fclose(f);
	return 0;
}

//파일과 콘솔에 달력 출력
void fprintf_calendar(FILE* f, int year) {
	int total;
	int startday;
	int leap;
	int goal_date;
	int monthcnt = 0;
	int totalcnt = 0;
	int max_month;
	total = get_total_dates(year);
	startday = (total +1 ) % 7; //시작요일 2001.01.01 이 월(1) 이니까 1 더해준다.
	
	//윤년에 따라 목표 설정
	leap = isLeap(year);
	if (leap == 1)
		goal_date = 366;
	else
		goal_date = 365;

	while (totalcnt != goal_date) {
		for (int month = 1; month <= 12; month++) {
			printf("         [%d년 %d월]\n", year, month);
			printf("----------------------------\n");
			printf("  일  월  화  수  목  금  토\n");
			
			fprintf(f,"         [%d년 %d월]\n", year, month);
			fprintf(f,"----------------------------\n");
			fprintf(f,"  일  월  화  수  목  금  토\n");

			//시작요일까지 공백
			for (int i = 0; i < startday; i++) {
				printf("    ");
				fprintf(f,"     ");
			}
				

			//각 달의 최대일까지 출력하며 총 365 or 366에 도달하면 멈춘다.
			max_month = get_max_day(leap, month);
			while (monthcnt != max_month){
				monthcnt++;
				totalcnt++;
				
				printf("%4d", monthcnt);
				fprintf(f, "%5d", monthcnt);
				if (  (monthcnt + startday ) % 7 == 0) { //토요일마다 띄운다.
					printf("\n");
					fprintf(f,"\n");
				}
				if (totalcnt == goal_date) {
					break; //12월에 채워지니까 알아서 for문까지도 나감
				}
			}
			startday = (startday + (monthcnt % 7) ) % 7; //안해주면 매달 같은 날 시작 
			monthcnt = 0;
			printf("\n\n");
			fprintf(f, "\n\n");
		}
	}
	

}
//2001.01.01 부터 해당 년도 전까지의 총 일수 계산
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
//year년 month 달의 끝날을 계산 
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

//윤년 검사 - 맞으면 1 반환
int isLeap(int year) {
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}