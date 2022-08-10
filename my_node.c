#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
typedef struct Node
{
   int data;
   struct Node *pNext;
}NODE,*pNODE;


pNODE CreateSgLinkList(void)
{
	int i, length, data;
	pNODE p_new = NULL, pTail = NULL;
	//创建头节点，头结点是第0个节点，后面的节点从1开始计数
	pNODE pHead = (pNODE)malloc(sizeof(NODE));

	if (NULL == pHead)
	{
		printf("内存分配失败！\n");
		exit(EXIT_FAILURE);
	}
 
	pHead->data = 0;
	pHead->pNext = NULL;
	pTail = pHead;
 
	printf("请输入要创建链表的长度：\n");
	scanf("%d", &length);
 
	for (i=1; i<length+1; i++)
	{
		p_new = (pNODE)malloc(sizeof(NODE));
      
		if (NULL == p_new)
		{
			printf("内存分配失败！\n");
			exit(EXIT_FAILURE);
		}
 
		printf("请输入第%d个节点的值：\n", i);
		scanf("%d", &data);
 
		p_new->data = data;
		p_new->pNext = NULL;
		pTail->pNext = p_new;
		pTail = p_new;
	}
	return pHead;
}


void TraverseSgLinkList(pNODE pHead)
{
	pNODE pt = pHead->pNext;
 
	printf("打印链表：\n");
	while (pt != NULL)
	{
		printf("%d ", pt->data);
		pt = pt->pNext;
	}
	putchar('\n');
}


int IsEmptySgLinkList(pNODE pHead)
{
	if (pHead->pNext == NULL)
		return 1;
	else
		return 0;
}
int GetListLength(pNODE pHead)
{
   int length = 0;
   pNODE p = pHead->pNext;
   while(p != NULL)
   {
      length++;
      p = p->pNext; 
   }
   return length;
}
void insertMylist(pNODE pHead,int addr,int data)
{
   pNODE pt = (pNODE)malloc(sizeof(NODE));
   pt->data = data;
   while(1)
   {
      if(pHead->data == addr)
      {
         pt->pNext = pHead->pNext;
         pHead->pNext = pt;
         break;
      }
      pHead=pHead->pNext;
   }
}
void deleteMylist(pNODE pHead,int addr)
{
	pNODE pt;
	while(1)
	{
		
		if(addr == pHead->data)
		{
			pHead = pHead->pNext;
			break;
		}
		pt = pHead;
		pHead = pHead->pNext;
		
	}
	pt->pNext = pHead->pNext;

}
int main ()
{
   pNODE Mylist = CreateSgLinkList();
   TraverseSgLinkList(Mylist);
   printf("length is %d \n",GetListLength(Mylist));
   insertMylist(Mylist,3,100);
   TraverseSgLinkList(Mylist);
   printf("delete %d \n",3);
   deleteMylist(Mylist,3);
   TraverseSgLinkList(Mylist);
   return(0);
}










