// 이진 탐색 트리에서는 항상 부모 노드가 왼쪽 자식보다는 크고, 오른쪽 자식 보다는 작다.
// 찾고자 하는 값이 부모 노드보다 작을 경우는 왼쪽 자식으로, 클 경우는 오른쪽 자식으로

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* insertNode(Node* root, int data) {
    if(root == NULL) {
	root = (Node*)malloc(sizeof(Node));
	root->leftChild = root->rightChild = NULL;
	root->data = data;
	return root;
    }
    else {
	if(root->data > data) {
	    root->leftChild = insertNode(root->leftChild, data);
	}
	else {
	    root->rightChild = insertNode(root->rightChild, data);
	}	
    }

    return root;
}


Node* searchNode(Node* root, int data) {
    if(root == NULL) return NULL;
    if(root->data == data) return root;
    else if(root->data > data) return searchNode(root->leftChild, data);
    else return searchNode(root->rightChild, data);
}

// 이진 탐색 트리의 가장 작은 원소 찾기 함수
// 이진 탐색 트리에서는 항상 부모 노드가 왼쪽 자식 보다 크기 때문 왼쪽 자식 노드만 확인하면 가장 작은 원소 찾기 가능
Node* findMinNode(Node* root) {
    Node* node = root;
    while(node->leftChild != NULL) {
	node = node->leftChild;
    }
    return node;
}
Node* deleteNode(Node* root, int data) {
    Node *node = NULL;
    if(root == NULL) return NULL;
    // 삭제하려는 노드의 data가 root노드의 data보다 작은 경우
    if(root->data > data) root->leftChild = deleteNode(root->leftChild, data);
    // 삭제하려는 노드의 data가 root노드의 data보다 큰 경우
    else if (root->data < data) root->rightChild = deleteNode(root->rightChild, data);
    else {
	// 자식이 모두 존재하는 경우
	if(root->leftChild != NULL && root->rightChild != NULL) {
	    node = findMinNode(root->rightChild);
	    root->data = node->data;
	    root->rightChild = deleteNode(root->rightChild, node->data);
	}
	// 자식이 하나만 존재하는 경우
	else {
	    node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
	    free(root);
	    return node;
	}
    }
    return root;
}

void preorder(Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
}

int main(void) {
    Node* root = NULL;
    root = insertNode(root, 30);
    root = insertNode(root, 17);
    root = insertNode(root, 48);
    root = insertNode(root, 5);
    root = insertNode(root, 23);
    root = insertNode(root, 37);
    root = insertNode(root, 50);
    deleteNode(root, 50);
    preorder(root);
    return 0;
}
