#pragma once

/*
单向链表，获取倒数第k个节点的值
*/
typedef struct Node {
	int data;
	struct Node *next;
}Lnode,*LinkList;


int getTailk1(LinkList head, int k);

int getTailk2(LinkList head, int k);
