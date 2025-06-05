#include <iostream>
// 快速排序算法实现
// 算法思想：分治法，通过一趟排序将待排记录分隔成独立的两部分
// 其中一部分记录的关键字均比另一部分的关键字小，则可分别对这两部分记录继续进行排序
// 记忆方法："挖坑填数" + "分而治之"
using namespace std;
int n;
// 分区函数：将数组分为两部分，返回枢轴位置
int Partition(int* a, int low, int high){
    // 步骤1：设置哨兵（枢轴元素）
    a[0] = a[low];  // 使用a[0]作为哨兵存储枢轴元素
    int key = a[0];  // 枢轴元素值
    // 步骤2：双向扫描交换元素
    while(low < high){
        // 从右向左找第一个小于key的值
        while(low < high && a[high] >= key) high--;
        a[low] = a[high];  // 将小于key的值移到左边
        
        // 从左向右找第一个大于key的值
        while(low < high && a[low] <= key) low++;
        a[high] = a[low];  // 将大于key的值移到右边
    }
    a[low] = a[0];
    return low;
}

// 快速排序递归函数
void QSort(int* a, int low, int high){
    if(low < high){
        // 步骤1：获取分区位置
        int ploc = Partition(a, low, high);
        
        // 输出当前排序结果（调试用）
        for(int i=1; i<=n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        
        // 步骤2：递归排序左子数组
        QSort(a, low, ploc-1);
        // 步骤3：递归排序右子数组
        QSort(a, ploc+1, high);
    }
}


int main(){
    // 输入数据
    cin >> n;
    int* a = new int[n+1];  // 动态分配数组，a[0]用作哨兵
    
    // 读取待排序数据
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    
    // 调用快速排序
    QSort(a, 1, n);
    
    // 释放内存
    delete[] a;
    return 0;
}