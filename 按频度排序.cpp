/*����һ��˫��ѭ������ÿ������г���pre��data��next�������⣬��������һ������Ƶ����freq��
������������ǰ��Ƶ����freq��ֵ����ʼ��Ϊ�㣬
�������������һ��LOCATE(L,x)�Ĳ���֮��
�����ʵĽ�㣨��Ԫ��ֵ����x�Ľڵ㣩�е�Ƶ����freq��ֵ����1��
ͬʱ���������н��֮��Ĵ���ʹ�䰴����Ƶ�ȷǵ�����˳�����У�
�Ա�ʼ�ձ��ֱ�Ƶ�����ʵĽ�����ǿ�����ͷ��㡣*/ 
# include <stdio.h>
# include <stdlib.h> 
# include <malloc.h>
# include <string.h>
# define TRUE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASIBLE -1
# define OVERFLOW -2
# define N 10
typedef int ElemType;
typedef int Status;
typedef struct Node
{
    ElemType data;
    struct Node *next;
    struct Node *pre;
    int freq;
}Node;
typedef struct Node *LinkList; 
Status InitList(LinkList &L) 
{ 
    L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if(L==NULL) /* 存储分配失败 */
            return ERROR;
    L->next=L->pre=L; 
    L->freq = 0;
    return OK;
}
void creatList(LinkList &L)
{
	int i;
	InitList(L);
	LinkList p;
	for (i = N-1; i>=0; i--)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = i;
		p->freq = 0;
		p->next = L->next;
		L->next->pre = p;
		p->pre = L;
		L->next = p;
	}
}
void ListTraverse(LinkList L)
{
	LinkList p=L->next;  
    while(p!=L)  
    {  
        printf("%d ",p->data); 
        p=p->next; 
    }    
}
Status LOCATE(LinkList &L,int x)
{
	LinkList p,q;
	p = L->next;
	q = L->next;
	while(p->data!=x&&p!=L)
		p = p->next;
	if(p == L)
		return ERROR;
	else
	{
		p->freq++;
		while(q!=L&&q->freq>=p->freq)
			q = q->next;
		if(q!=p->next)
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
			p->pre = q->pre;
			q->pre->next = p;
			q->pre = p;
			p->next = q;	
		} 	
	} 
	return OK; 
}
int main()
{
	LinkList L;
	creatList(L);
	LOCATE(L,3);
	ListTraverse(L);
}
