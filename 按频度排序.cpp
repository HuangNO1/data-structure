/*设有一个双向循环链表，每个结点中除有pre，data和next三个域外，还增设了一个访问频度域freq。
在链表被起作用前，频度域freq的值均初始化为零，
而当对链表进行一次LOCATE(L,x)的操作之后，
被访问的结点（即元素值等于x的节点）中的频度域freq的值便增1，
同时调整链表中结点之间的次序，使其按访问频度非递增的顺序排列，
以便始终保持被频繁访问的结点总是靠近表头结点。*/ 
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
    L=(LinkList)malloc(sizeof(Node)); /* 浜х敓澶寸粨鐐�,骞朵娇L鎸囧悜姝ゅご缁撶偣 */
    if(L==NULL) /* 瀛樺偍鍒嗛厤澶辫触 */
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
