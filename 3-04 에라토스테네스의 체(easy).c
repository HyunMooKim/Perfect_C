#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//1~600까지 소수를 판단하는 프로그램.
//문제 조건에 나오는 에라토스테네스의 체 알고리즘 설명에 따라서 만들었다.

int prime[601] = { 0 }; 

int main() {
	int cnt = 0; 
	//step 1 : 2~600까지 모두 우선 1 체크
	for (int i = 2; i <= 600; i++) {
		prime[i] = 1;
	}
	//step 2 : sqrt(600) 의 배수까지 n이 하나씩 증가하며, n의 2배수 이상에 해당하는 숫자는 0으로 체크
	for (int n = 2; n <= sqrt(600); n++) {
		for (int i = 2 ; n * i <= 600; i++) {
			prime[n * i] = 0;
		}
	}

	//출력 
	for (int i = 1; i <= 600; i++) {
		if (prime[i] == 1) {
			printf("%4d", i);
			cnt++;
			if (cnt % 20 == 0) {
				printf("\n");
			}
		}
	}

	return 0;
}

