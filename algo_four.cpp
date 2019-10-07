#include "algo_four.h"
#include <iostream>

/*
单向链表，遍历链表，获取链表的长度，然后减去k长度的节点，
则链表最后一个节点是原链表的倒数第k个节点
*/
int getTailk1(LinkList head, int k)
{
	LinkList current = head;
	int size = 0;
	while (current !=  NULL)
	{
		size++;
		current = current->next;
	}
	current = head;
	for (int i = 0; i < size - k; i++)
	{
		current = current->next;
	}
	return current->data;
}

/*
定义两个指针，pfast,pflow,
pfast提前从头结点提前走k-1步，然后两个指针开始往后走，
当pfast到达尾结点，pslow所指结点就是倒数第k个结点
*/
int getTailk2(LinkList head, int k)
{
	LinkList pfast = head, pslow = head;
	int i = 1;
	while (i < k)
	{
		pfast = pfast->next;
		if (pfast == NULL)
		{
			std::cout << "wrong" << std::endl;
			exit(1);
		}
		i++;
	}
	while (pfast->next != NULL)
	{
		pfast = pfast->next;
		pslow = pslow->next;
	}
	return pslow->data;
}