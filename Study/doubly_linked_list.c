#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

void insert(Node *head,Node *tail, int data){
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node *cur;
	cur = head->next;
	while(cur->data < data && cur != tail){
		cur = cur->next;
	}
	Node *prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;
}

void removeFront(Node *head, Node *tail){
	Node *node = head->next;
	head->next = node->next;
	Node *next = node->next;
	next->prev = head;
	free(node);
}
void showAll(Node *head, Node *tail){
	Node *cur = head->next;
	while(cur != tail) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int main(void){
	Node *head = (Node*)malloc(sizeof(Node));
	Node *tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = NULL;
	tail->prev = head;
	tail->next = NULL;
	insert(head, tail, 1);
	insert(head, tail, 2);
	insert(head, tail, 3);
	insert(head, tail, 4);
	insert(head, tail, 5);
	insert(head, tail, 6);
	removeFront(head, tail);
	showAll(head, tail);
	return 0;
}
