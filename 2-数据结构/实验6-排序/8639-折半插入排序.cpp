#include <iostream>
#include <vector>
using namespace std;

/* 折半插入排序算法实现
 * 算法思想：在直接插入排序基础上，使用二分查找确定插入位置
 * 记忆方法：先二分查找定位，再插入，结合了二分查找和插入排序的优点
 */

int main(){
    // 输入数据
    int n;  // 元素个数
    cin >> n;
    vector<int> v(n+1, 0);  // 使用v[0]作为哨兵
    for(int i=1; i<=n; i++){
        cin >> v[i];  // 输入待排序元素
    }

    // 折半插入排序核心算法
    for(int i=2; i<=n; i++){  // 从第二个元素开始
        v[0] = v[i];  // 设置哨兵
        int low=1, high=i-1;  // 初始化查找范围
        
        // 二分查找确定插入位置
        while(low<=high){
            int mid = (low+high)/2;
            if(v[0]<v[mid]) high = mid-1;  // 在前半部分继续查找
            else low = mid+1;  // 在后半部分继续查找
        }
        
        // 移动元素腾出插入位置
        for(int j=i-1; j>=high+1; j--) v[j+1] = v[j];
        v[high+1] = v[0];  // 插入元素到正确位置

        // 输出每趟排序结果
        for(int i=1; i<=n; i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}