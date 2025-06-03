#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量
using namespace std;
typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)
{
    S.top = S.base = (int*)malloc(sizeof(int)*STACK_INIT_SIZE);
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S,SElemType e)
{
    if(S.top - S.base >= S.stacksize-1) return ERROR;
    *(++S.top) = e;
    return OK;

}

Status Pop(SqStack &S,SElemType &e)
{
    if(S.base == S.top) return ERROR;
    e = *S.top;
    S.top--;
    return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
    if(S.base == S.top) return ERROR;
    e = *S.top;

}

int StackLength(SqStack S)
{
    return S.top - S.base;

}


Status StackTraverse(SqStack S)
{
// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p  =  S.top;        //请填空
	if(p == S.base)printf("The Stack is Empty!"); //请填空
	else
	{
		printf("The Stack is: ");
		while(p != S.base)            //请填空
		{
                           //请填空
			printf("%d ", *p);
			p--;

		}
	}
	printf("\n");
	return OK;
}

int main()
{
     int a;
     SqStack S;
SElemType x, e;
     if(InitStack(S))    // 判断顺序表是否创建成功，请填空
{
	printf("A Stack Has Created.\n");
}

while(1)
	{
    printf("1:Push \n2:Pop \n3:Get the Top \n4:Return the Length of the Stack\n5:Load the Stack\n0:Exit\nPlease choose:\n");
	scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d", &x);
		      if(!Push(S, x)) printf("Push Error!\n"); // 判断Push是否合法，请填空
		      else printf("The Element %d is Successfully Pushed!\n", x);
		      break;
		case 2: if(!Pop(S, e)) printf("Pop Error!\n"); // 判断Pop是否合法，请填空
			  else printf("The Element %d is Successfully Poped!\n", e);
		  	  break;
		case 3: if(!GetTop(S, e))printf("Get Top Error!\n"); // 判断Get Top是否合法，请填空
			  else printf("The Top Element is %d!\n", e);
		   	  break;
			case 4: printf("The Length of the Stack is %d!\n",StackLength(S)); //请填空
				  break;
			case 5: StackTraverse(S);  //请填空
				  break;
			case 0: return 1;
		}
	}

}

/*
输入格式
测试样例格式说明：
根据菜单操作：
1、输入1，表示要实现Push操作，紧跟着输入要Push的元素
2、输入2，表示要实现Pop操作
3、输入3，返回栈顶元素
4、输入4，返回栈的元素个数
5、输入5，表示从栈顶到栈底输出栈的所有元素
6、输入0，表示程序结束


输入样例
1
2
1
4
1
6
5
3
4
2
5
2
2
2
0


输出样例
A Stack Has Created.
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 2 is Successfully Pushed!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 4 is Successfully Pushed!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 6 is Successfully Pushed!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Stack is: 6 4 2 
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Top Element is 6!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Length of the Stack is 3!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 6 is Successfully Poped!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Stack is: 4 2 
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 4 is Successfully Poped!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
The Element 2 is Successfully Poped!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
Pop Error!
1:Push 
2:Pop 
3:Get the Top 
4:Return the Length of the Stack
5:Load the Stack
0:Exit
Please choose:
*/