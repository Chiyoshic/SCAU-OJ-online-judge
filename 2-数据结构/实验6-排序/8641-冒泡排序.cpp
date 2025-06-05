    #include <iostream>
using namespace std;

/* 冒泡排序算法实现
 * 算法思想：通过相邻元素比较交换，将最大元素逐步"冒泡"到数组末尾
 * 记忆方法：相邻比较，大数下沉，小数上浮，类似气泡上升
 */

int main(){
    // 输入数据
    int n;  // 元素个数
    cin >> n;
    int* a = new int[n];  // 动态分配数组
    for(int i=0; i<n; i++){
        cin >> a[i];  // 输入待排序元素
    }
    // 冒泡排序核心算法
    for(int i=0; i<n-1; i++){  // 外层循环控制排序轮数
        int flag = 1;  // 优化标志，若一轮未交换则提前结束
        for(int j=0; j<n-i-1; j++){  // 内层循环控制每轮比较次数
            if(a[j] > a[j+1]){  // 相邻元素比较
                flag = 0;  // 发生交换，标志位置0
                // 交换相邻元素
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
        // 输出每趟排序结果
        for(int k=0; k<n; k++){
            cout << a[k] << " " ;
        }
        cout << endl;
        if(flag) break;  // 提前终止优化
    }

    delete[] a;  // 释放动态数组
    return 0;
}