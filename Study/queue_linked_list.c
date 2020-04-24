#include<stdio.h>
#include<stdlib.h>
#define INF 99999999

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *front;
	Node *rear;
	int count;
} Queue;

void push(Queue *queue, int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	
	// 현재 큐에 아무 데이터도 없을 경우
	if(queue->count == 0){
		queue->front = node;
	}

	// 현재 큐에 데이터가 있을 경우
	// 새로 들어올 노드를 현재 마지막노드(rear)의 다음노드 연결
	else {
		queue->rear->next = node;
	}
	
	// 마지막 노드를 새로 들어올 노드로 변경
	queue->rear = node;
	queue->count++;
}

int pop(Queue *queue) {
	if(queue->count == 0) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node *node = (Node*)malloc(sizeof(Node));
	int data;
	node = queue->front;
	data = node->data;
	queue->front = queue->front->next;
	queue->count--;
	free(node);
	return data;
}

void show(Queue *queue) { 
	Node *cur = queue->front;
	printf("--- 큐의 앞 ---\n");
	while(cur != NULL){
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 큐의 뒤 ---\n");
}

int main(void) {
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.count = 0;
	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	pop(&queue);
	push(&queue, 6);
	pop(&queue);
	show(&queue);
	return 0;
}

