// 해시 : 특정한 값을 찾고자 할 떄는 그 값의 키로 접근할 수 있다. 
// 일반적으로 해시 함수는 모듈로 연산 등의 수학적 연산으로 이루어져 있으므로 O(1) 만에 값에 접근이 가능하다.
// 해시의 충돌 : 입력 값으로는 어떠한 값이나 모두 가능하지만, 해시 함수를 거쳐 생성되는 키의 경우 키의 중복이 발생가능 하다.
// 해싱 알고리즘 : 나눗셈 법이 가장 많이 활용된다. 입력 값을 테이블의 크기로 나눈 나머지를 키로 이용
// 충돌을 처리하는 방법 1. 충돌을 발생시키는 항목을 해시 테이블의 다른 위치에 저장 : 선형 조사법, 이차 조사법
// 충돌을 처리하는 방법 2. 해시 테이블의 하나의 버킷에 여러 개의 항목을 저장 : 체이닝 등

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

typedef struct {
    int id;
    char name[20];
} Student;


// 해시 테이블을 초기화한다.
void init(Student** hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
	hashTable[i] = NULL;
    }
}

// 해시 테이블의 메모리를 반환합니다.
void destructor(Student** hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
	if (hashTable[i] != NULL) {
	    free(hashTable[i]);
	}
    }
}

// 해시 테이블 내 빈 공간을 선형 탐색으로 찾습니다.
int findEmpty(Student** hashTable, int id) {
    int i = id % TABLE_SIZE;
    while (1) {
	if (hashTable[i % TABLE_SIZE] == NULL) {
	    return i % TABLE_SIZE;
	}
	i++;
    }
}

// 특정한 ID 값에 매칭되는 데이터를 해시 테이블 내에서 찾습니다.
int search(Student** hashTable, int id) {
    int i = id % TABLE_SIZE;
    while (1) {
	if(hashTable[i % TABLE_SIZE] == NULL) return -1;
	else if(hashTable[i % TABLE_SIZE]->id == id) return i;
	i++;
    }
}

void add(Student** hashTable, Student* input, int key) {
    hashTable[key] = input;
}

Student* getValue(Student** hashTable, int key) {
    return hashTable[key];
}

void show(Student** hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
	if(hashTable[i] != NULL) {
	    printf("키 : [%d] 이름 : [%s]\n", i, hashTable[i]->name);
	}
    }
}

int main(void) {
    Student **hashTable;
    hashTable = (Student**)malloc(sizeof(Student) * TABLE_SIZE);
    init(hashTable);

    for (int i = 0; i < INPUT_SIZE; i++) {
	Student* student = (Student*)malloc(sizeof(Student));
	student->id = rand() % 1000000;
	sprintf(student->name, "사람%d", student->id);
	if (search(hashTable, student->id) == -1) {
	    int index = findEmpty(hashTable, student->id);
	    add(hashTable, student, index);
	}
    }

    show(hashTable);
    destructor(hashTable);
    return 0;
}
