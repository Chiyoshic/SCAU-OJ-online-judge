#include"stdlib.h" /* malloc()等 */
#include"stdlib.h" /* exit() */
#include"stdio.h"
#define EQ(a,b) ((a)==(b))
#define SUCCESS 1
#define UNSUCCESS 0
#define NULLKEY -1 /*哈希表无元素时值为-1*/
typedef int ElemType;
int length;
typedef struct
{
   ElemType *elem; /* 数据元素存储基址，动态分配数组 */
   int count; /* 当前数据元素个数 */
}HashTable;

void InitHashTable(HashTable *H)
 { /* 操作结果: 构造一个长度为length的哈希表,length为全局变量 */
   int i;
   (*H).count=0; /* 当前元素个数为0 */
   (*H).elem=(ElemType*)malloc(length*sizeof(ElemType));
   if(!(*H).elem)
     exit(0); /* 存储分配失败 */
   for(i=0;i<length;i++)
     (*H).elem[i]=NULLKEY; /* 未填记录的标志 */
}

// ——————————————————填空——————————————————
int Hash(ElemType K)
{ /* 一个简单的哈希函数*/
    return (3*K) % length;
}
void collision(int *p) /*线性探测再散列 */
{ /* 开放定址法处理冲突 */
    (++*p) %= length;

// ——————————————————填空——————————————————




}
int SearchHash(HashTable H,ElemType K,int *p,int *c)
{  /* 在开放定址哈希表H中查找关键码为K的元素,若查找成功,以p指示待查数据 */
   /* 元素在表中位置,并返回SUCCESS;否则,以p指示插入位置,并返回UNSUCCESS */
   /* c用以计冲突次数，其初值置零，供建表插入时参考。算法9.17 */
   *p=Hash(K); /* 求得哈希地址 */
   while(H.elem[*p] != NULLKEY && !EQ(K,H.elem[*p]))
   { /* 该位置中填有记录,并且关键字不相等 */
     (*c)++;
     if(*c<length)
	   collision(p); /* 求得下一探查地址p */
     else
       break;
   }
   if EQ(K,H.elem[*p])
     return SUCCESS; /* 查找成功，p返回待查数据元素位置 */
   else
     return UNSUCCESS; /* 查找不成功(H.elem[p].key==NULLKEY)，p返回的是插入位置 */
}
int InsertHash(HashTable *H,ElemType e)
{ /* 查找不成功时插入数据元素e到开放定址哈希表H中，并返回查找长度 */
   int c,p;
   c=0;
   if(SearchHash(*H,e,&p,&c))   /* 表中已有与e有相同关键字的元素 */
     printf("哈希表中已有元素%d。\n",e);
   else{ /* 插入e */
     (*H).elem[p]=e;
     ++(*H).count;
   }
   return c+1; /*查找长度为冲突次数加1*/
}
void TraverseHash(HashTable H)
 { /* 按哈希地址的顺序打印哈希表，无元素位置用X表示 */
   int i;
   //printf("HashTable Address:0～%d\n",length-1);
   for(i=0;i<length;i++)
     if(H.elem[i]==NULLKEY) /* 有数据 */
       printf("X ");
	 else
		 printf("%d ",H.elem[i]);
	 printf("\n");
}
main()
{
	float i=0,j=0;
	ElemType e;
	HashTable H;
         //printf("Input Table length:");
	scanf("%d",&length);
	InitHashTable(&H);
	//printf("Input key words sequence, -1 conclusion input：");
	scanf("%d",&e);
	while(e!=-1)
	{
		j ++;  /*j记录输入元素个数*/
		i = i + InsertHash(&H,e);  /*i记录查找长度的和*/
		scanf("%d",&e);
	}
	TraverseHash(H);
	printf("Average search length=%f\n",i/j);
}

/*
输入格式
第一行：输入哈希表的长度；
第二行：输入关键字序列，用空格分隔，-1结束(-1不作为关键字)。


输出格式
第一行：输出哈希表里的数据，未使用的单元用X表示；
第二行：输出平均查找长度,格式为"Average search length="。


输入样例
11
22 41 53 46 30 13 1 67 -1


输出样例
22 X 41 30 1 53 46 13 67 X X
Average search length=2.000000
*/