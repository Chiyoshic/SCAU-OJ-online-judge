#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;

int CreateLink_L(LinkList &L,int n){
// 鍒涘缓鍚湁n涓厓绱犵殑鍗曢摼琛?
  LinkList p,q;
  int i;
  ElemType e;
  L = new LNode;
  L->next = NULL;              // 先建立一个带头结点的单链表
  q = L;
  for (i=0; i<n; i++) {
    scanf("%d", &e);
    p = new LNode;  // 生成新结点
    // 请补全代码
	p->data=e;
	p->next=NULL;
	q->next=p;
	q=p;
  }
  return OK;
}

int LoadLink_L(LinkList &L){
// 单链表遍历
 LinkList p = L->next;
 if(p==NULL)printf("The List is empty!\n"); // 请填空
 else
 {
	 printf("The LinkList is:");
	 while(p!=NULL)    // 请填空
	 {
		printf("%d ",p->data); 
		p=p->next;    // 请填空
	 }
 }
 printf("\n");
 return OK;
}

int LinkInsert_L(LinkList &L,int i,ElemType e){
// 算法2.9
// 在带头结点的单链线性表L中第i个位置之前插入元素e
// 请补全代码
LinkList p=L,q;
int j=0;
 while (p && j < i-1 ) {
        p = p->next;
        j++;
    }
    if(!p||j>i-1) return ERROR;
	q = new LNode;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

int LinkDelete_L(LinkList &L,int i, ElemType &e){
// 算法2.10
// 在带头结点的单链线性表L中，删除第i个元素，并用e返回其值
// 请补全代码
LinkList p=L,pp=L;
    int j = 0;
    while (p->next && j < i ) {
        pp = p;
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i ) return ERROR;
    e = p->data;
    pp->next = p->next;
    free(p);
    return OK;
}
int reverseList(LinkList &L){
	LinkList next,current=L->next,rh=NULL,pcu=NULL;
	if(!L||!L->next) return ERROR;
	while(current!=NULL){
		next=current->next;
		current->next=pcu;
		pcu=current;
		current=next;
	}
	L->next=pcu;
	return OK;
}

int main()
{
 LinkList T;
 int a,n,i;
 ElemType x, e;
 printf("Please input the init size of the linklist:\n");
 scanf("%d",&n);
 printf("Please input the %d element of the linklist:\n", n);
 if(CreateLink_L(T,n)==OK)     // 判断链表是否创建成功，请填空
 {
	 printf("A Link List Has Created.\n");
	 LoadLink_L(T);
 }
 while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
				  if(LinkInsert_L(T,i,x)==ERROR) printf("Insert Error!\n"); // 判断i值是否合法，请填空
				  else printf("The Element %d is Successfully Inserted!\n", x); 
				  break;
			case 2: scanf("%d",&i);
				  if(LinkDelete_L(T,i,e)==ERROR) printf("Delete Error!\n"); // 判断i值是否合法，请填空
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: LoadLink_L(T);
				  break;
			case 4: reverseList(T);
				  break;
			case 0: return 1;
		}
	}
	return 0;
}
