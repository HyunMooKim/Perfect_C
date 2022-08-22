#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
#include <windows.h>
#define WIDTH 76
#define HEIGHT 22
char grid[HEIGHT + 1][WIDTH + 1];

void SetColor(int ForgC);

int main() {
	double x;
	double y;
	int x_value = 0;
	int y_value = 0;
	//배경 공백으로 채우기
	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			grid[i][j] = ' ';
		}
	}
	//y축, x축 그리기
	for (int i = 0; i < HEIGHT + 1; i++) {
		grid[i][38] = '|';
	}
	for (int i = 0; i < WIDTH + 1; i++) {
		grid[11][i] = '-';
	}

	//축의 숫자 그리기
	grid[11 - 1][38 - 31] = '-';
	grid[11 - 1][38 - 30] = '3';
	grid[11 + 1][38 + 30] = '3';
	grid[11 - 10][38 - 1] = '1';
	grid[11 + 10][38 + 1] = '-';
	grid[11 + 10][38 + 2] = '1';

	//sin 함수 그리기.  그래프 중간은 [11][38]이며, 1칸은 0.1로 설정했다.
	x = -3.14159;
	while (x < 3.24159) {
		y = sin(x);
		if (x < 0) {
			x_value = 38 + (int)(x * 10);
		}
		else {
			x_value = 38 + (int)(x * 10);
		}
		
		if (y < 0) {
			y_value = 11 - (int)(y * 10);
		}
		else {
			y_value = 11 - (int)(y * 10);
		}

		grid[y_value][x_value] = '*';
		x = x + 0.1;
	}

	//그래프 출력
	SetColor(12); //연빨강
	SetColor(9); //연파랑
	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1 ; j++) {
			if (grid[i][j] == '|' || grid[i][j] == '-') {
				SetColor(9);
			}
			else if (grid[i][j] == '*') {
				SetColor(12);
			}
			else
				SetColor(8);
			printf("%c", grid[i][j]); 
		}
		printf("\n");
	}
	return 0;
}

//주어진 함수
void SetColor(int ForgC) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	WORD wColor;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

