#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
void printprime(int n);
void ispalindrome(int input);
int main(void) 
{
	int input_1;
	int input_2;
	printf("2부터 몇 개의 소수를 출력할까요? >>: ");
	scanf("%d", &input_1);
	printprime(input_1);
	
	printf("\n회수판단프로그램\n회수인지 검사할 수 입력: ");
	scanf_s("%d", &input_2);
	ispalindrome(input_2);

}
void printprime(int n)
{
	int k = 2; //소수는 2부터 출발
	int count1 = 0; // 2부터 해당 수까지 검사하며 나누어진다면(소수가 아니라면)  count1을 1로 바꿔준다.
	int count2 = 0; //출력되고 있는 소수 개수
	
	do 
	{
		count1 = 0; // 소수인지 알아볼때마다 다시 초기화해준다
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
			count2++; //몇개 출력인지 저장
			if (count2 % 10 == 0)
				printf("\n");
		}
		k++; 
	} while (count2 != n); //n개 출력되면 반복문 탈출


}


void ispalindrome(int input)
{
	int num = 1; //1부터 올라가면서 자리수가 홀수갠지 짝수갠지 확인하자
	int countsoo = 1; // 자리수
	int save[300] = { 0 }; // 각 자리수를 저장할 배열
	int count = 0; //소수판단처럼 

	// 자리수 몇개인지 먼저 확인해 보자
	do
	{
		if (input / (int)pow(10, num) > 0)//십의자리부터 올라가며 있는지 확인 pow(int a, int b) 가 double이라 첨에 오류남
		{
			countsoo++;
		}
		else
			break; // 자리수가 더이상 없으면 stop

		num++;

	} while (1);


	printf("자리수는 %d \n\n", countsoo);

	for (int i = countsoo; i >= 1; i--) // 큰 자리수부터 숫자 하나씩으로 저장해보자
	{
		save[i] = input / (int)pow(10, i - 1); //큰 자리수부터 하나씩 추출

		input = input - save[i] * (int)pow(10, i - 1); //저장한 큰 자리수는 쳐낸다
		printf("%d 번 자리수: %d\n", i, save[i]);

	}
	for (int i = 1; i <= countsoo / 2; i++) //이제 맨앞 맨뒤부터 같은지 확인 => i j  양끝부터 ++ -- 해도 될듯?
	{
		if (save[i] != save[countsoo - i + 1]) // 쌍쌍비교해서 다른 부분이 있다면
		{
			printf("결론:  회수가 아닙니다.");
			count++;
			break;
		}

	}
	if (count == 0)
	{
		printf("결론:  회수입니다.");
	}
	return;
}
