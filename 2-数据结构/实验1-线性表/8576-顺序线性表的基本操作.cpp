#include<stdio.h>
#include<stdlib.h>
#define OK 1 
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
// 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
// 请补全代码
	L.elem = (int*)malloc( LIST_INIT_SIZE*sizeof(int) );
	L.length = 0;
	L.listsize = 100;
	if( L.elem == NULL ) return ERROR;
	return OK;

}

int Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
	int i;
	if(L.length == 0) printf("The List is empty!");  // 请填空
	else
	{
		printf("The List is: ");
		for(i=0; i<L.length; i++) printf("%d ",L.elem[i]);  // 请填空
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
// 算法2.4，在顺序线性表L中第i个位置之前插入新的元素e
// i的合法值为1≤i≤L.length +1
// 请补全代码
	if(L.length == L.listsize) return ERROR;
	if(i>L.length+1) return ERROR;
	if(L.length == 0) {L.elem[0] = e; L.length++; return OK;}
	int j;
	for(j=L.length; j>=i; j--) L.elem[j] = L.elem[j-1];
	L.elem[i-1] = e;
	L.length++;
	return OK;

}

int ListDelete_Sq(SqList &L,int i, int &e)
{
// 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值
// i的合法值为1≤i≤L.length
// 请补全代码
	if(L.length == 0) return ERROR;
	if(i<1 || i>L.length ) return ERROR;
	int j;
	e = L.elem[i-1];
	for(j=i-1; j<=L.length-1; j++) L.elem[j] = L.elem[j+1];
	L.length--;
	return OK;

}

int main()
{
	SqList T;
	int a, i;
	ElemType e, x;
	if( InitList_Sq(T) )    // 判断顺序表是否创建成功
	{
		printf("A Sequence List Has Created.\n");
	}
	while(1)
	{
		printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d%d",&i,&x);
					if(!ListInsert_Sq(T, i, x)) printf("Insert Error!\n"); // 执行插入函数，根据返回值判断i值是否合法
					else printf("The Element %d is Successfully Inserted!\n", x); 
					break;
			case 2: scanf("%d",&i);
					if(!ListDelete_Sq(T, i, e)) printf("Delete Error!\n"); // 执行删除函数，根据返回值判断i值是否合法
					else printf("The Element %d is Successfully Deleted!\n", e);
					break;
			case 3: Load_Sq(T);
					break;
			case 0: return 1;
		}
	}
}

/*
Description 编写算法，
创建初始化容量为LIST_INIT_SIZE的顺序表T
并实现插入、删除、遍历操作。本题目给出部分代码，请补全内容。*/