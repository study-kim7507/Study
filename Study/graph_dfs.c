// 깊이 우선 탐색 : 탐색을 함에 있어서 보다 깊은 것을 우선적으로하여 탐색하는 알고리즘, 스택 자료구조에 기초
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1001

typedef struct {
    int index;
    struct Node *next;
} Node;

Node **a;
int n, m, c[MAX_SIZE];

void addFront(Node *root, int index) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

void dfs(int x) {
    if(c[x]) return;
    c[x] = 1;
    printf("%d ", x);
    Node *cur = a[x]->next;
    while(cur != NULL){
	int next = cur->index;
	dfs(next);
	cur = cur->next;
    }
}

int main(void) {
    int num, temp = 0;
    scanf("%d %d", &n, &m);
    a = (Node**)malloc(sizeof(Node*) * MAX_SIZE);
    for(int i = 1; i <= n; i++) {
	a[i] = (Node*)malloc(sizeof(Node));
	a[i]->next = NULL;
    }

    for(int i = 0; i < m; i++) {
	int x, y;
	scanf("%d %d", &x, &y);
	if(i == 0) temp = x;
	addFront(a[x], y);
	addFront(a[y], x);
    }
    dfs(temp);
    return 0;
}
