#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//project 1-01 단위변환 - easy
int main(void)
{
    double length;
    int from = 0, to = 0;  // switch에 쓸거라 초기값 필요
    double unit[4][4] = { {1,39.37,3.28,1.09},
                          {0.025,1,0.083,0.027},
                          {0.304,12,1,0.34},
                          {0.914,36 ,3, 1} };
    const char* ary[4] = { "미터", "인치", "피트", "야드" };
    printf("[1]미터(m) [2]인치(in) [3]피트(ft) [4]야드(yd) [0]종료\n\n");
    printf("[이전단위]->[변환단위], 두 개의 메뉴 번호를 선택하세요 >> ");
    scanf("%d %d", &from,&to);


    printf("\n[이전 단위]의 길이를 입력하세요 >> ");
    scanf("%lf", &length);
    while (length != 0) {
        printf("\n[result] %.2lf(%s) --> %.2lf(%s)\n", length, ary[from-1], length * unit[from-1][to-1], ary[to-1]);
        printf("\n[이전 단위]의 길이를 입력하세요 >> ");
        scanf("%lf", &length);
    }
    printf("종료합니다.");
    return 0;
}