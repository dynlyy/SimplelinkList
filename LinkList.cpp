#include<stdio.h>
#include<stdlib.h>
typedef struct List{
     char data;
	 struct List *next;
}ListCode,*LinkList;

bool InitList(LinkList &L){    //初始化链表
    L = (ListCode*)malloc(sizeof(LinkList));
	if(L==NULL)
		return false;
	L->next = NULL;
	return true;
}

bool InsertList(LinkList &L,int i,char s){     //插入链表数据   L是链表,i是插入位置,s是插入的数据
	if(i<0){                       //增强代码的健壮性
	         return false;
	}
	//↓这段代码用于做插入的准备工作
	int j=0;                                   //先定义一个j用来作为哨兵
	ListCode *H;                               //定义一个指针，用来作为哨兵指针
	H = L;                                     //先让指针和头指针相等 
	while(H!=NULL&&j<i-1){                              //两个哨兵相互配合，找到插入位置的前一个位置，并令哨兵指针指向插入位置的前一个位置
		H=H->next;                             
		j++;
	}
	//↓这段代码做插入
	LinkList p = (ListCode*)malloc(sizeof(ListCode));  //定义新结点
	p->data = s;                                        //把要插入的数据先存入该结点
	p->next = H->next;                                 //先做后继结点的链接
	H->next = p;                                        //再做前面结点的链接    （两个链接不能交换位置，不然插入结点讲无限指向自己）
	return true;
}

bool InsertPriorNode(ListCode *p,char e){            //在指定指针位置插入数据                       
	if(p==NULL){                                     //增强代码健壮性
	     return false; 
	}
	LinkList L = (LinkList)malloc(sizeof(ListCode));  //向内存申请一个新的结点
	L->next = p->next;                                //↓把新结点放在插入结点后面
	p->next = L;                                      //↑把新结点放在插入结点后面
	L->data=p->data;                                  //把指定结点的数据放在新节点
	p->data=e;                                        //把要插入的数据放在指定结点
	return true;
}

bool ListDelete(LinkList &L,int i){                  //删除第i个结点
	if(i<1){
	     return false;
	}
	int j=0;
	ListCode *p;
	p=L;
	while(j<i-1){
		p=p->next;
		j++;
	}
	ListCode *q = p->next;
	p->next=q->next;
	printf("删除%c完成\n",q->data);
	free(q);
	return true;
}
bool DeleteNode(LinkList &L,ListCode *p){         //删除指定指针位置的元素     
	if(p->next==NULL)
	{
		printf("不能删除最后一个结点我很菜\n");
		return true;
	}
	ListCode *q = p->next;                         //把后继结点的元素放在指定位置，再把后继结点删除（偷梁换柱）
    p->data = q->data;
	p->next = q->next;
	printf("已经删除指定指针位置的元素%c",q->data);
	free(q);
	return true;
}
void printList(LinkList &L){          //打印该链表
    ListCode *p;
	p=L;
	for(int i=0;;i++)
	{
		p=p->next;
		if(p!=NULL)
		{
		printf("%c\n",p->data);
		}
		else
		{
			printf("打印单链表完成");
			return;
		}	
	}
}
bool GetElem(LinkList &L,int i){      //查找该链表的第i个元素
	if(i<1){
	     printf("查找的元素位置应该是正整数");
	     return true;
	}
	ListCode *p = L;
	int j = 0;
	for(j;j<i;){
		p=p->next;
		j++;
	}
	printf("第%d个元素为%c\n",i,p->data);
	return true;
}
bool LocateElem(LinkList &L,char e){  //查找指定元素
	int j=0;
	ListCode *p=L;
	while(p!=NULL)
	{
		if(p->data==e)
		{
		    printf("您要查到的%c元素在第%d个位置\n",e,j);
			return true;
		}
		p=p->next;
		j++;
	}
	printf("链表里没有您要查找的元素\n");
	return true;
}

int Length(LinkList &L){
	int length=0;
	ListCode *p=L;
	for(;;){
		if(p->next!=NULL)
		{
			p=p->next;
			length++;
		}
		else
		{
			return length;
		}
	}
}
int main()
{
	LinkList L;     //或者  *ListCode L
	InitList(L);    //初始化结点
	char *a="abc";
	InsertList(L,1,a[0]);
	InsertList(L,2,a[1]);
	InsertList(L,3,a[2]);
 	printf("%d\n",Length(L));
	system("pause");
	return 0;
}