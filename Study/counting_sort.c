// 크기를 기준으로 데이터의 개수를 세는 정렬 알고리즘
#include <stdio.h>
#define MAX_VALUE 10001

int n, m;
int a[MAX_VALUE];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		// 배열의 크기 10001 보다 큰 값 즉, 10002 부터는 계수 정렬 불가능
		// 너무 많은 메모리를 소모함.
		a[m]++; 
	}
	for(int i = 0; i < MAX_VALUE; i++) {
		while(a[i] != 0) {
			printf("%d ", i);
			a[i]--;
		}
	}
	return 0;
}
		
