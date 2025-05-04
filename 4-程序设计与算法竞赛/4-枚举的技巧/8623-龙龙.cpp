#include <stdio.h>  // 只需stdio.h头文件用于输入输出
#include <math.h>   // 用于计算平方根

/*
 * 函数功能：计算H(n) = Σ(n/i) (i从1到n)
 * 优化原理：
 * 1. 分块计算：利用n/i的值会重复的特性，将计算分为两部分
 * 2. 第一部分：当i <= sqrt(n)时，计算(n/i - n/(i+1))*i
 * 3. 第二部分：当i > sqrt(n)时，直接计算n/i
 * 时间复杂度：O(sqrt(n))，相比暴力O(n)大幅优化
 */
long func(int n)
{
    long s = 0;  // 存储累加结果
    int i, q;    // q = floor(sqrt(n))
    
    if(n < 1) return 0;  // 处理边界情况
    
    q = sqrt(n);  // 计算分界点
    
    /* 第一部分：处理i <= q的情况
     * 技巧：利用n/i的值会重复的特性，批量计算
     * 对于每个i，(n/i - n/(i+1))表示有多少个j满足n/j=i
     */
    for(i = 1; i <= q; i++)
        s += (n/i - n/(i+1)) * i;
    
    /* 第二部分：处理i > q的情况
     * 此时n/i < q，直接计算每个n/i的值
     */
    for(i = 1; i <= n/(q+1); i++)
        s += n/i;
    
    return s;
}

/*
 * 主函数：处理多组测试数据
 * 输入格式：
 * 第一行T表示测试用例数
 * 接下来T行，每行一个整数n
 */
int main()
{
    int a;    // 存储输入的n值
    int n;    // 测试用例数
    
    scanf("%d", &n);  // 读取测试用例数
    while(n--)
    {
        scanf("%d", &a);  // 读取每个测试用例
        printf("%ld\n", func(a));  // 输出计算结果
    }
    
    return 0;
}    
/*
Description
下边有个很简单的函数，希望大家
求出它的返回值：

long long H(int n){
    long long res = 0;
    int i;
    for(i = 1; i <= n; i=i+1 ){
        res = (res + n/i);
    }
    return res;
}

不过直接使用这个函数是会超时的，必须改造这个函数，当然这一定难不到未来的编程高手--你



输入格式
第一行是数字T(T<=1021)表示case数，接下来T 行，每行一个整数n，n是一个32 位整数（保证可以由int 表示）。


输出格式
函数返回值。


输入样例
2
5
10


输出样例
10
27
*/