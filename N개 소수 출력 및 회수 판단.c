#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
void printprime(int n);
void ispalindrome(int input);
int main(void) 
{
	int input_1;
	int input_2;
	printf("2���� �� ���� �Ҽ��� ����ұ��? >>: ");
	scanf("%d", &input_1);
	printprime(input_1);
	
	printf("\nȸ���Ǵ����α׷�\nȸ������ �˻��� �� �Է�: ");
	scanf_s("%d", &input_2);
	ispalindrome(input_2);

}
void printprime(int n)
{
	int k = 2; //�Ҽ��� 2���� ���
	int count1 = 0; // 2���� �ش� ������ �˻��ϸ� ���������ٸ�(�Ҽ��� �ƴ϶��)  count1�� 1�� �ٲ��ش�.
	int count2 = 0; //��µǰ� �ִ� �Ҽ� ����
	
	do 
	{
		count1 = 0; // �Ҽ����� �˾ƺ������� �ٽ� �ʱ�ȭ���ش�
		for (int i = 2; i < k; i++)
		{
			if (k % i == 0)
			{
				count1++;
				break;
			}
		}
		if (count1 == 0)
		{
			printf("%d ", k);
			count2++; //� ������� ����
			if (count2 % 10 == 0)
				printf("\n");
		}
		k++; 
	} while (count2 != n); //n�� ��µǸ� �ݺ��� Ż��


}


void ispalindrome(int input)
{
	int num = 1; //1���� �ö󰡸鼭 �ڸ����� Ȧ������ ¦������ Ȯ������
	int countsoo = 1; // �ڸ���
	int save[300] = { 0 }; // �� �ڸ����� ������ �迭
	int count = 0; //�Ҽ��Ǵ�ó�� 

	// �ڸ��� ����� ���� Ȯ���� ����
	do
	{
		if (input / (int)pow(10, num) > 0)//�����ڸ����� �ö󰡸� �ִ��� Ȯ�� pow(int a, int b) �� double�̶� ÷�� ������
		{
			countsoo++;
		}
		else
			break; // �ڸ����� ���̻� ������ stop

		num++;

	} while (1);


	printf("�ڸ����� %d \n\n", countsoo);

	for (int i = countsoo; i >= 1; i--) // ū �ڸ������� ���� �ϳ������� �����غ���
	{
		save[i] = input / (int)pow(10, i - 1); //ū �ڸ������� �ϳ��� ����

		input = input - save[i] * (int)pow(10, i - 1); //������ ū �ڸ����� �ĳ���
		printf("%d ���� �ڸ���: %d\n", i, save[i]);

	}
	for (int i = 1; i <= countsoo / 2; i++) //���� �Ǿ� �ǵں��� ������ Ȯ�� => i j  �糡���� ++ -- �ص� �ɵ�?
	{
		if (save[i] != save[countsoo - i + 1]) // �ֺֽ��ؼ� �ٸ� �κ��� �ִٸ�
		{
			printf("���:  ȸ���� �ƴմϴ�.");
			count++;
			break;
		}

	}
	if (count == 0)
	{
		printf("���:  ȸ���Դϴ�.");
	}
	return;
}