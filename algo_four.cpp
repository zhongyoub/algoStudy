#include "algo_four.h"
#include <iostream>

/*
������������������ȡ����ĳ��ȣ�Ȼ���ȥk���ȵĽڵ㣬
���������һ���ڵ���ԭ����ĵ�����k���ڵ�
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
��������ָ�룬pfast,pflow,
pfast��ǰ��ͷ�����ǰ��k-1����Ȼ������ָ�뿪ʼ�����ߣ�
��pfast����β��㣬pslow��ָ�����ǵ�����k�����
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