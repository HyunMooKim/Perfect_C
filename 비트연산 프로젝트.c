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
        printf("[1] ��Ʈ and\n\n [2]��Ʈ or\n\n [3] ��Ʈ xor\n\n [4] ��Ʈ complement(~) \n\n [0] ����\n\n �� ������ �ϳ��� �����ϼ��� >>");
        scanf_s("%d", &cal);

        if (cal == 4)
        {
            printf("������ ���� x �ϳ� �Է� >>");
            scanf_s("%d", &x);
            printf("x= ");
            for (d = 31; d >= 0; d--)
            {
                printf("%d", (x >> d & 1)); // x�� ��Ʈ�� ���
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
            printf("����");
            return 0;
        }
        else
        {
            printf("������ �� ���� x y �Է� >>");
            scanf_s("%d %d", &x, &y);

            printf("x = ");
            for (a = 31; a >= 0; a--) // x�� ��Ʈ�� ���
            {
                printf("%d", (x >> a & 1));
            }
            printf("   %d\n", x); //������ ���� �����ֱ�

            printf("y = ");
            for (b = 31; b >= 0; b--)
            {
                printf("%d", (y >> b & 1)); // y�� ��Ʈ�� ���
            }

            printf("   %d\n", y);

            switch (cal)
            {
            case 1:
                z = x & y;
                printf("x & y = ");
                for (c = 31; c >= 0; c--)
                {
                    printf("%d", (z >> c & 1)); // z = x&y�� ��Ʈ�� ���
                }
                printf("   %d\n", z);
                break;

            case 2:
                z = x | y;
                printf("x | y = ");
                for (c = 31; c >= 1; c--)
                {
                    printf("%d", (z >> c & 1)); // z = x&y�� ��Ʈ�� ���
                }
                printf("   %d\n", z);
                break;

            case 3:
                z = x ^ y;
                printf("x ^ y = ");
                for (c = 31; c >= 0; c--)
                {
                    printf("%d", (z >> c & 1)); // z = x&y�� ��Ʈ�� ���
                }
                printf("   %d\n", z);
                break;

            default:
                printf("����� �Է���");
            }
        }

    } while (cal <= 4);


    return 0;
}