#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//project 1-01 ������ȯ - easy
int main(void)
{
    double length;
    int from = 0, to = 0;  // switch�� ���Ŷ� �ʱⰪ �ʿ�
    double unit[4][4] = { {1,39.37,3.28,1.09},
                          {0.025,1,0.083,0.027},
                          {0.304,12,1,0.34},
                          {0.914,36 ,3, 1} };
    const char* ary[4] = { "����", "��ġ", "��Ʈ", "�ߵ�" };
    printf("[1]����(m) [2]��ġ(in) [3]��Ʈ(ft) [4]�ߵ�(yd) [0]����\n\n");
    printf("[��������]->[��ȯ����], �� ���� �޴� ��ȣ�� �����ϼ��� >> ");
    scanf("%d %d", &from,&to);


    printf("\n[���� ����]�� ���̸� �Է��ϼ��� >> ");
    scanf("%lf", &length);
    while (length != 0) {
        printf("\n[result] %.2lf(%s) --> %.2lf(%s)\n", length, ary[from-1], length * unit[from-1][to-1], ary[to-1]);
        printf("\n[���� ����]�� ���̸� �Է��ϼ��� >> ");
        scanf("%lf", &length);
    }
    printf("�����մϴ�.");
    return 0;
}