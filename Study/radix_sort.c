// 자릿수를 기준으로 차례대로 데이터를 정렬하는 알고리즘
#include<stdio.h>
#define MAX 10000

void radixSort(int *a, int n) {
	int res[MAX], maxValue = 0;
	int exp = 1;
	// 최댓값의 자릿수를 구한다.
	for(int i = 0; i < n; i++) {
		if(a[i] > maxValue) maxValue = a[i];
	}
	while (maxValue / exp > 0) {
		int bucket[10] = { 0 };
		for(int i = 0; i < n; i++) bucket[a[i] / exp % 10]++; // 자릿수 계산
		for(int i = 1; i < 10; i++) bucket[i] += bucket[i-1]; // 자릿수 누적계산
		for(int i = n - 1; i >= 0; i--) {
			res[--bucket[a[i] / exp % 10]] = a[i];
		}
		for(int i = 0; i < n; i++) {
			a[i] = res[i];
		}
		exp *= 10;
	}
}

int main(void) {
	int a[MAX];
	int i, n;
	scanf("%d" , &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	radixSort(a, n);
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
