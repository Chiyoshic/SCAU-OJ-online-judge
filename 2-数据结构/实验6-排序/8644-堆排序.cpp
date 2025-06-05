#include <iostream>
// 堆排序算法实现
// 算法思想：利用堆这种数据结构设计的排序算法，分为建堆和排序两个阶段
// 记忆方法："大顶堆" - 父节点总是大于子节点，每次取堆顶元素
using namespace std;
int n;

// 堆调整函数：保持以s为根的子树满足堆性质
void HeapAdjust(int* a, int s, int m){
    int root = a[s];  // 保存当前根节点值
    // 从根节点开始向下调整
    for(int j=2*s; j<=m; j*=2){
        // 步骤1：选择较大的子节点
        if(j<m && a[j] < a[j+1]) j++;
        // 步骤2：如果根节点大于子节点，调整结束
        if(root >= a[j]) break;
        // 步骤3：将较大的子节点上移
        a[s] = a[j];
        s = j;
    }
    // 将初始根节点值放入最终位置
    a[s] = root;
}

// 建堆函数：从最后一个非叶子节点开始调整
void CreateHeap(int* a){
    // 从n/2开始（最后一个非叶子节点）向前调整
    for(int i=n/2; i>0; i--){
        HeapAdjust(a, i, n);
    }
}

int main(){
    // 输入数据
    cin >> n;
    int* a = new int[n+1];  // 动态分配数组，a[0]不使用
    
    // 读取待排序数据
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    // 步骤1：建立初始堆
    CreateHeap(a);

    // 输出初始堆
    for(int j=1; j<=n; j++){
        cout << a[j] << " ";
    }
    cout << endl;

    // 步骤2：堆排序过程
    for(int i=n; i>1; i--){
        // 交换堆顶元素与当前最后一个元素
        int x = a[1];
        a[1] = a[i];
        a[i] = x;
        
        // 调整剩余元素为新堆
        HeapAdjust(a, 1, i-1);
        
        // 输出当前排序结果
        for(int j=1; j<=n; j++){
            cout << a[j] << " ";
        }
        cout << endl;
    }


    // 释放内存
    delete[] a;
    return 0;
}