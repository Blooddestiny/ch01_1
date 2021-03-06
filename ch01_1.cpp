// ch01_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//ch01
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct {
	int data;
}ElemType;

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList &A) {
	A.elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if (!A.elem) exit(OVERFLOW);
	A.length = 0;
	A.listsize = LIST_INIT_SIZE;
	return OK;
}

void BubbleSort(SqList A, int n) {
	int temp;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (A.elem[j].data > A.elem[j + 1].data)
			{
				temp = A.elem[j].data;
				A.elem[j].data = A.elem[j + 1].data;
				A.elem[j + 1].data = temp;
			}
}

Status ListInsert_Sq(SqList &A, int i, ElemType e) {
	if (i<1 || i>A.length+1) return ERROR;
	if (A.length > A.listsize) {
		ElemType *newbase;
		newbase = (ElemType *)realloc(A.elem, (A.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		A.elem = newbase;
		A.listsize += LISTINCREMENT;
	}
	ElemType *p, *q;
	q = &(A.elem[i - 1]);
	for (p = &(A.elem[A.length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	A.length++;
	return OK;
}

int main()
{
	SqList A;
	ElemType e;
	int j;
	InitList_Sq(A);
	printf("请输入要输入的数据个数:");
	int n;
	scanf_s("%d", &n);
	printf("请输入数据:");
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &A.elem[i].data);
		A.length++;
	}
	BubbleSort(A, n);
	printf("排序后:");
	for (int i = 0; i < A.length; i++)
		printf("%d ", A.elem[i].data);
	printf("\n");
	printf("请输入要插入元素的位置和元素:");
	scanf_s("%d %d", &j, &e.data);
	ListInsert_Sq(A, j, e);
	for (int i = 0; i < A.length; i++)
		printf("%d ", A.elem[i].data);

	return 0;
}

