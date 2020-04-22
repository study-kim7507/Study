#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	struct Node *next;
} Node;

void addFront(Node *head, int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->next = head->next;
	node->data = data;
	head->next = node;
}

void removeFront(Node *head){
	Node *front = head->next;
	head->next = front->next;
	free(front);
}

void freeAll(Node *head) {
	Node *cur = head->next;
	while(cur != NULL){
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
}

void showAll(Node *head) {
	Node *cur = head->next;
	while(cur != NULL){
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main(void){
	Node *head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	addFront(head, 1);
	addFront(head, 2);
	addFront(head, 3);
	addFront(head, 4);
	addFront(head, 5);
	removeFront(head);
	showAll(head);
	freeAll(head);
	return 0;
}
