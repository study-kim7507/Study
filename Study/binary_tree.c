#include<stdio.h>
#include<stdlib.h>

typedef struct {
	// 실제로는 int형 데이터 뿐만아니라 더 많은 데이터를 넣을 수 있다. 
	int data;
	struct Node *leftChild;
	struct Node *rightChild;
} Node;

// 특정 노드를 초기화하는 함수
Node* initNode(int data, Node* leftChild, Node* rightChild) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = leftChild;
	node->rightChild = rightChild;
	return node;
}

//전위 순회 : 자기 자신 -> 왼쪽 자식 -> 오른쪽 자식
void preorder(Node *root) {
	if(root) {
		printf("%d ", root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}
//중위 순회 : 왼쪽 자식 -> 자기 자신 -> 오른쪽 자식
//중위 순회의 경우 트리 왼쪽에서 오른쪽으로 출력하는 것과 동일
void inorder(Node* root) {
	if(root) {
		inorder(root->leftChild);
		printf("%d ", root->data);
		inorder(root->rightChild);
	}
}
//후위 순회 : 왼쪽 자식 -> 오른쪽 자식 -> 자기 자신
void postorder(Node* root) {
	if(root) {
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%d ", root->data);
	}
}

int main(void) {
	Node* n7 = initNode(50, NULL, NULL);
	Node* n6 = initNode(37, NULL, NULL);
	Node* n5 = initNode(23, NULL, NULL);
	Node* n4 = initNode(5, NULL, NULL);
	Node* n3 = initNode(48, n6, n7);
	Node* n2 = initNode(17, n4, n5);
	Node* n1 = initNode(30, n2, n3);
	preorder(n1);
	printf("\n");
	inorder(n1);
	printf("\n");
	postorder(n1);
	printf("\n");
	return 0;
}
