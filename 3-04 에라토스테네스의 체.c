#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//1~600���� �Ҽ��� �Ǵ��ϴ� ���α׷�.
//���� ���ǿ� ������ �����佺�׳׽��� ü �˰��� ���� ���� �������.

int prime[601] = { 0 }; 

int main() {
	int cnt = 0; 
	//step 1 : 2~600���� ��� �켱 1 üũ
	for (int i = 2; i <= 600; i++) {
		prime[i] = 1;
	}
	//step 2 : sqrt(600) �� ������� n�� �ϳ��� �����ϸ�, n�� 2��� �̻� �ش��ϴ� ���ڴ� 0���� üũ
	for (int n = 2; n <= sqrt(600); n++) {
		for (int i = 2 ; n * i <= 600; i++) {
			prime[n * i] = 0;
		}
	}

	//��� 
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

