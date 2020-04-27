//우선순위 큐 : 우선 순위를 가진 데이터들을 저장하는 큐.
//데이터를 꺼낼 때 우선 순위가 높은 데이터가 가장 먼저 나온다.
//일반적인 형태의 큐는 선형적인 형태
//우선순위 큐는 트리구조로 보는 것이 합리적 -> 완전 이진 트리
//최대 힙(Max Heap) 부모 노드가 자식 노드보다 값이 큰 완전 이진 트리
//최대 힙은 루트 노드가 항상 큰 값.

#include <stdio.h>
#define MAX_SIZE 10000

void swap(int *a ,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct {
	int heap[MAX_SIZE];
	int count;
} priorityQueue;

void push(priorityQueue *pq, int data) {
	if(pq->count >= MAX_SIZE) return;
	pq->heap[pq->count] = data;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	while(now > 0 && pq->heap[now] > pq->heap[parent]) {
		swap(&pq->heap[now], &pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

int pop(priorityQueue *pq) {
	if(pq->count <= 0) return -9999;
	int res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	while(leftChild < pq->count) {
		if(pq->heap[target] < pq->heap[leftChild]) target = leftChild;
		if(pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;
		if(target = now) break;
		else {
			swap(&pq->heap[now], &pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 1;
		}
	}
	return res;
}

int main(void) {
	int n, data;
	scanf("%d" ,&n);
	priorityQueue pq;
	pq.count = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &data);
		push(&pq, data);
	}
	for(int i = 0; i < n; i++) {
		int data = pop(&pq);
		printf("%d ", data);
	}
	return 0;
}
