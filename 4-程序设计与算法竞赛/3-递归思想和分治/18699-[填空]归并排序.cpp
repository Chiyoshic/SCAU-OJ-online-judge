/*
 * 归并排序算法实现
 * 算法思想：分治法(Divide and Conquer)
 * 1. 分解：将当前区间分成两半
 * 2. 解决：递归地对两个子区间进行排序
 * 3. 合并：将两个已排序的子区间合并成一个有序区间
 * 
 * 记忆口诀：
 * 一分为二递归排，两两合并有序来
 * 临时数组辅助用，空间换得时间快
 */
#include <iostream>
using namespace std;
int n;                  // 待排序元素个数
int data[1001];         // 存储待排序数据的数组
int temp[1001];         // 临时数组，用于合并过程

/**
 * 归并排序核心函数
 * @param A 待排序数组指针
 * @param x 区间起始下标(包含)
 * @param y 区间结束下标(不包含)
 * @param T 临时数组指针
 */
void merge_sort(int* A, int x, int y, int* T) {
    // 递归终止条件：区间长度大于1才需要排序
    if(y-x > 1){
        /* 分治步骤开始 */
        int m = (x+y)/2;        // 计算中点，将区间一分为二
        merge_sort(A, x, m, T); // 递归排序左半部分
        merge_sort(A, m, y, T); // 递归排序右半部分
        /* 分治步骤结束 */
        /* 合并步骤开始 */
        int p = x, q = m, i = x; // p:左区间指针 q:右区间指针 i:临时数组指针
        
        // 合并两个有序子区间
        while(p < m || q < y) {
            // 选择较小的元素放入临时数组
            // 情况1：右区间已遍历完 或 左区间未遍历完且左元素<=右元素
            if(q >= y || (p < m && A[p] <= A[q]))
                T[i++] = A[p++]; // 取左区间元素
            else
                T[i++] = A[q++]; // 取右区间元素
        }
        
        // 将临时数组中已排序的元素复制回原数组
        for(i = x; i < y; i++) A[i] = T[i];
        /* 合并步骤结束 */
    }
}

int main()
{
    // 输入数据
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>data[i];
        
    // 调用归并排序
    merge_sort(data, 0, n, temp);
    
    // 输出排序结果
    for(int i=0; i<n; i++)
        cout<<data[i]<<endl;
}
/*
Description
从键盘输入N个数，使用归并排序进行排序后，由小到大输出。

#include <iostream>
using namespace std;
int n;
int data[1001];
int temp[1001];
void merge_sort(int* A, int x, int y, int* T) {
  if(y-x > 1){
_______________________
    int p = x, q = m, i = x;
    while(p < m || q < y) {
      if(q >= y || (p < m && A[p] <= A[q]))
        T[i++] = A[p++];
      else
        T[i++] = A[q++];
    }
    for(i = x; i < y; i++) A[i] = T[i];
  }
}

int main()
{
    // 输入数据
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>data[i];
        
    // 调用归并排序
    merge_sort(data, 0, n, temp);
    
    // 输出排序结果
    for(int i=0; i<n; i++)
        cout<<data[i]<<endl;
}


输入格式
第一行，第一个数是N（N<1000）
第二行，N个数，空格分隔


输出格式
由小到大输出一行一个数


输入样例
6
1 2 3 6 5 4


输出样例
1
2
3
4
5
6
*/