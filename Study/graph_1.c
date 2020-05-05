// 무방향 비가중치 그래프 : 간선에 방향성이 없고, 가중치가 없는 그래프
#include <stdio.h>

int a[1001][1001];
int n, m;

int main(void) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
	int x, y;
	scanf("%d %d", &x, &y);
	a[x][y] = 1;
	a[y][x] = 1;
    }

    for(int i = 1; i <= n; i++) {
	for(int j = 1; j <= n; j++) {
	    printf("%d ", a[i][j]);
	}
	printf("\n");
    }
    return 0;
}
