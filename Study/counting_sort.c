// ũ�⸦ �������� �������� ������ ���� ���� �˰���
#include <stdio.h>
#define MAX_VALUE 10001

int n, m;
int a[MAX_VALUE];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		// �迭�� ũ�� 10001 ���� ū �� ��, 10002 ���ʹ� ��� ���� �Ұ���
		// �ʹ� ���� �޸𸮸� �Ҹ���.
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
		
