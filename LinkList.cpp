#include<stdio.h>
#include<stdlib.h>
typedef struct List{
     char data;
	 struct List *next;
}ListCode,*LinkList;

bool InitList(LinkList &L){    //��ʼ������
    L = (ListCode*)malloc(sizeof(LinkList));
	if(L==NULL)
		return false;
	L->next = NULL;
	return true;
}

bool InsertList(LinkList &L,int i,char s){     //������������   L������,i�ǲ���λ��,s�ǲ��������
	if(i<0){                       //��ǿ����Ľ�׳��
	         return false;
	}
	//����δ��������������׼������
	int j=0;                                   //�ȶ���һ��j������Ϊ�ڱ�
	ListCode *H;                               //����һ��ָ�룬������Ϊ�ڱ�ָ��
	H = L;                                     //����ָ���ͷָ����� 
	while(H!=NULL&&j<i-1){                              //�����ڱ��໥��ϣ��ҵ�����λ�õ�ǰһ��λ�ã������ڱ�ָ��ָ�����λ�õ�ǰһ��λ��
		H=H->next;                             
		j++;
	}
	//����δ���������
	LinkList p = (ListCode*)malloc(sizeof(ListCode));  //�����½��
	p->data = s;                                        //��Ҫ����������ȴ���ý��
	p->next = H->next;                                 //������̽�������
	H->next = p;                                        //����ǰ���������    ���������Ӳ��ܽ���λ�ã���Ȼ�����㽲����ָ���Լ���
	return true;
}

bool InsertPriorNode(ListCode *p,char e){            //��ָ��ָ��λ�ò�������                       
	if(p==NULL){                                     //��ǿ���뽡׳��
	     return false; 
	}
	LinkList L = (LinkList)malloc(sizeof(ListCode));  //���ڴ�����һ���µĽ��
	L->next = p->next;                                //�����½����ڲ��������
	p->next = L;                                      //�����½����ڲ��������
	L->data=p->data;                                  //��ָ���������ݷ����½ڵ�
	p->data=e;                                        //��Ҫ��������ݷ���ָ�����
	return true;
}

bool ListDelete(LinkList &L,int i){                  //ɾ����i�����
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
	printf("ɾ��%c���\n",q->data);
	free(q);
	return true;
}
bool DeleteNode(LinkList &L,ListCode *p){         //ɾ��ָ��ָ��λ�õ�Ԫ��     
	if(p->next==NULL)
	{
		printf("����ɾ�����һ������Һܲ�\n");
		return true;
	}
	ListCode *q = p->next;                         //�Ѻ�̽���Ԫ�ط���ָ��λ�ã��ٰѺ�̽��ɾ����͵��������
    p->data = q->data;
	p->next = q->next;
	printf("�Ѿ�ɾ��ָ��ָ��λ�õ�Ԫ��%c",q->data);
	free(q);
	return true;
}
void printList(LinkList &L){          //��ӡ������
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
			printf("��ӡ���������");
			return;
		}	
	}
}
bool GetElem(LinkList &L,int i){      //���Ҹ�����ĵ�i��Ԫ��
	if(i<1){
	     printf("���ҵ�Ԫ��λ��Ӧ����������");
	     return true;
	}
	ListCode *p = L;
	int j = 0;
	for(j;j<i;){
		p=p->next;
		j++;
	}
	printf("��%d��Ԫ��Ϊ%c\n",i,p->data);
	return true;
}
bool LocateElem(LinkList &L,char e){  //����ָ��Ԫ��
	int j=0;
	ListCode *p=L;
	while(p!=NULL)
	{
		if(p->data==e)
		{
		    printf("��Ҫ�鵽��%cԪ���ڵ�%d��λ��\n",e,j);
			return true;
		}
		p=p->next;
		j++;
	}
	printf("������û����Ҫ���ҵ�Ԫ��\n");
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
	LinkList L;     //����  *ListCode L
	InitList(L);    //��ʼ�����
	char *a="abc";
	InsertList(L,1,a[0]);
	InsertList(L,2,a[1]);
	InsertList(L,3,a[2]);
 	printf("%d\n",Length(L));
	system("pause");
	return 0;
}