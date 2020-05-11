// 해시 (체이닝) 
// 체이닝 기법은 연결리스트를 활용해 특정한 키를 가지는 항목들을 연결하여 저장한다.
// 연결 리스트를 사용한다는 점에서 삽입과 삭제가 용이합니다. 테이블 크기 재설정 문제는 '동적할당' 을 통해서 손쉽게 해결할 수 있다.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

// 체이닝 구조체 정의
typedef struct {
    int id;
    char name[20];
} Student;

typedef struct {
    Student* data;
    struct Bucket* next;
} Bucket;

// 해시 테이블을 초기화 합니다.
void init(Bucket** hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
	hashTable[i] = NULL;
    }
}

// 해시 테이블의 메모리를 반환합니다.
void destructor(Bucket** hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
	if(hashTable[i] != NULL) {
	    free(hashTable[i]);
	}
    }
}

int isExist(Bucket** hashTable, int id) {
    int i = id % TABLE_SIZE;
    if(hashTable[i] == NULL) return 0;
    else {
	Bucket* cur = hashTable[i];
	while(cur != NULL) {
	    if(cur->data->id == id) return 1;
	    cur = cur->next;
	}
    }
    return 0;
}

// 특정한 키 인덱스에 데이터를 삽입한다.
void add(Bucket** hashTable, Student* input) {
    int i = input->id % TABLE_SIZE;
    if(hashTable[i] == NULL) {
	hashTable[i] = (Bucket*)malloc(sizeof(Bucket));
	hashTable[i]->data = input;
	hashTable[i]->next = NULL;
    }
    else {
	Bucket* cur = (Bucket*)malloc(sizeof(Bucket));
	cur->data = input;
	cur->next = hashTable[i];
	hashTable[i] = cur;
    }
}

void show(Bucket** hashTable) {
    for(int i = 0; i < TABLE_SIZE; i++) {
	if(hashTable[i] != NULL) {
	    Bucket *cur = hashTable[i];
	    while (cur != NULL) {
		printf("키 : [%d] 이름 : [%s]\n", i, cur->data->name);
		cur = cur->next;
	    }
	}
    }
}

int main(void) {
    Bucket** hashTable;
    hashTable = (Bucket**)malloc(sizeof(Bucket) * TABLE_SIZE);
    init(hashTable);

    for(int i = 0; i < INPUT_SIZE; i++) {
	Student* student = (Student*)malloc(sizeof(Student));
	student->id = rand() % 1000000;
	sprintf(student->name, "사람%d", student->id);
	if(!isExist(hashTable, student->id)) {
	    add(hashTable, student);
	}
    }

    show(hashTable);
    destructor(hashTable);
    return 0;
}
