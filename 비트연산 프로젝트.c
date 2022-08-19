#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
    int cal;
    int x, y, z;
    int a, b, c, d;

    do
    {
        printf("[1] 비트 and\n\n [2]비트 or\n\n [3] 비트 xor\n\n [4] 비트 complement(~) \n\n [0] 종료\n\n 위 연산중 하나를 선택하세요 >>");
        scanf_s("%d", &cal);

        if (cal == 4)
        {
            printf("연산할 정수 x 하나 입력 >>");
            scanf_s("%d", &x);
            printf("x= ");
            for (d = 31; d >= 0; d--)
            {
                printf("%d", (x >> d & 1)); // x의 비트값 출력
            }
            printf("   %d\n", x);
            
            z = ~x;
            printf("~x =");
            for (c = 31; c >= 0; c--)
            {
                printf("%d", (z >> c & 1));
            }
            printf("   %d\n", z);
        }
        else if (cal == 0) {
            printf("종료");
            return 0;
        }
        else
        {
            printf("연산할 두 정수 x y 입력 >>");
            scanf_s("%d %d", &x, &y);

            printf("x = ");
            for (a = 31; a >= 0; a--) // x의 비트값 출력
            {
                printf("%d", (x >> a & 1));
            }
            printf("   %d\n", x); //십진수 값도 보여주기

            printf("y = ");
            for (b = 31; b >= 0; b--)
            {
                printf("%d", (y >> b & 1)); // y의 비트값 출력
            }

            printf("   %d\n", y);

            switch (cal)
            {
            case 1:
                z = x & y;
                printf("x & y = ");
                for (c = 31; c >= 0; c--)
                {
                    printf("%d", (z >> c & 1)); // z = x&y의 비트값 출력
                }
                printf("   %d\n", z);
                break;

            case 2:
                z = x | y;
                printf("x | y = ");
                for (c = 31; c >= 1; c--)
                {
                    printf("%d", (z >> c & 1)); // z = x&y의 비트값 출력
                }
                printf("   %d\n", z);
                break;

            case 3:
                z = x ^ y;
                printf("x ^ y = ");
                for (c = 31; c >= 0; c--)
                {
                    printf("%d", (z >> c & 1)); // z = x&y의 비트값 출력
                }
                printf("   %d\n", z);
                break;

            default:
                printf("제대로 입력해");
            }
        }

    } while (cal <= 4);


    return 0;
}