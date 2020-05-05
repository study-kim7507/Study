// 방향 가중치 그래프 : 간선이 방향을 가지며, 가중치가 있는 그래프, 방향 가중치 그래프가 주어졌을 때 연결되어있는 상황을 인접 리스트로 출력할 수 있습니다.

#include<stdio.h>
#include<stdlib.h>

typedef struct { 
    int index;
    int distance;
    struct Node *next;
} Node;

// 연결 리스트 삽입 함수
void addFront(Node *root, int index, int distance) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->distance = distance;
    node->next = root->next;
    root->next = node;
}

// 연결 리스트 출력 함수
void showAll(Node *root) {
    Node *cur = root->next;
    while(cur != NULL) {
	printf("%d (거리 : %d) ", cur->index, cur->distance);
	cur = cur->next;
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    Node **a = (Node**)malloc(sizeof(Node*) * n + 1);
    for(int i = 1; i <= n; i++) {
	a[i] = (Node*)malloc(sizeof(Node));
	a[i]->next = NULL;
    }
    for(int i = 0; i < m; i++){
	int x, y, distance;
	scanf("%d %d %d", &x, &y, &distance);
	addFront(a[x], y, distance);
    }
    for(int i = 1; i <= n; i++) {
	printf("원소 [%d] : ", i);
	showAll(a[i]);
	printf("\n");
    }
    return 0;
}
