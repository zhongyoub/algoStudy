#pragma once

/*
����������ȡ������k���ڵ��ֵ
*/
typedef struct Node {
	int data;
	struct Node *next;
}Lnode,*LinkList;


int getTailk1(LinkList head, int k);

int getTailk2(LinkList head, int k);
