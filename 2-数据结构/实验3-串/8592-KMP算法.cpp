#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#define TRUE  1
#define FALSE  0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
#define MAXSTRLEN  255 	//用户可在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN+1];	//0号单元存放串的长度

void get_next(SString T,int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T[0]) {
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int Index_KMP(SString S,SString T,int pos)
{
    // 算法4.6
    // 利用模式串T的next函数求T在主串S中第pos个字符之后的位置
    // KMP算法。请补全代码
    int* next = new int[T[0]+1];
    int i=pos, j=1;
    get_next(T, next);
    while(i<=S[0] && j<=T[0]){
        if(j==0 || S[i] == T[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j>T[0]) return i-T[0];
    else return 0;
}
int main()
{
    SString T,S;
    int i,j,n;
    char ch;
    int pos;
    scanf("%d",&n);    // 指定n对需进行模式匹配的字符串
    ch=getchar();
    for(j=1; j<=n; j++)
    {
        ch=getchar();
        for( i=1; i<=MAXSTRLEN&&(ch!='\n'); i++)  // 录入主串
        {
            S[i]=ch;
            ch=getchar();
        }
        S[0]=i-1;    // S[0]用于存储主串中字符个数
        ch=getchar();
        for( i=1; i<=MAXSTRLEN&&(ch!='\n'); i++)  // 录入模式串
        {
            T[i]=ch;
            ch=getchar();
        }
        T[0]=i-1;    // T[0]用于存储模式串中字符个数
        pos=Index_KMP(S, T, 1);    // 请填空
        printf("%d\n",pos);
    }
    return 0;
}

/* STL VERSION
#include <iostream>
#include <algorithm>
 
using namespace std;
typedef long long i64;
 
void solve()
{
    string a;
    string b;
    cin>>a>>b;
    int ans=a.find(b);
    printf("%d\n",ans+1);
}
 
int main()
{
    int T=1;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}
*/
