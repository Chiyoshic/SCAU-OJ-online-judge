#include <iostream>
// 归并排序(非递归)算法实现
// 算法思想：分治法，将数组分成若干子序列进行两两归并，逐步扩大有序子序列长度
// 记忆方法："分而治之" + "两两归并"
using namespace std;

// 归并函数：将两个有序子序列合并为一个有序序列
void mergeSort(int* a, int low, int mid, int high, int *c){
    int ia = low;    // 左子序列起始位置
    int ib = mid+1;  // 右子序列起始位置
    int ic = low;    // 临时数组起始位置
    
    // 步骤1：两两比较，选择较小的元素放入临时数组
    while(ia <= mid && ib <= high){
        if(a[ia] <= a[ib]){
            c[ic++] = a[ia++];
        }else{
            c[ic++] = a[ib++];
        }
    }
    
    // 步骤2：将剩余元素放入临时数组
    while(ia<=mid) c[ic++] = a[ia++];
    while(ib<=high) c[ic++] = a[ib++];
}

int main(){
    // 输入数据
    int n;
    cin >> n;
    
    // 动态分配数组
    int *a = new int[n+1];  // 原数组
    int *c = new int[n+1];  // 临时数组
    
    // 计算初始中点
    int mid;
    if(n%2==0) mid = n/2;
    else mid = (n+1)/2;

    // 读取待排序数据
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    // 归并排序主过程
    int cnt = 1;  // 记录归并轮次
    for(int i=1; i<n; i*=2){  // i表示当前子序列长度
        // 对每个子序列进行归并
        for(int low=1; low <= n; low+= 2*i){
            int mid = min(low+i-1, n);   // 计算中点
            int high = min(low+2*i-1, n); // 计算终点
            
            // 交替使用原数组和临时数组
            if(cnt%2!=0) mergeSort(a, low, mid, high, c);
            else mergeSort(c, low, mid, high, a);
        }
        
        // 输出当前排序结果
        int* temp = (cnt % 2 == 0) ? a : c;
        for(int j=1; j<=n; j++) cout << temp[j] << " ";
        cout << endl;
        cnt++;
    }

    // 释放内存
    delete[] a;
    delete[] c;
    return 0;
}