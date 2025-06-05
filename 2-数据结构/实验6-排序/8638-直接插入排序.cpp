#include <iostream>
#include <vector>
using namespace std;

/* 直接插入排序算法实现
 * 算法思想：将待排序元素插入到已排序序列的适当位置
 * 记忆方法：类似整理扑克牌，每次将新牌插入到已排序牌中的正确位置
 */

int main(){
    // 输入数据
    int n;  // 元素个数
    cin >> n;
    vector<int> v(n+1, 0);  // 使用v[0]作为哨兵
    for(int i=1; i<=n; i++){
        cin >> v[i];  // 输入待排序元素
    }

    // 直接插入排序核心算法
    for(int i=2; i<v.size(); i++){  // 从第二个元素开始
        if(v[i] < v[i-1]){  // 当前元素小于前一个元素时才需要插入
            v[0] = v[i];  // 设置哨兵
            v[i] = v[i-1];  // 后移元素
            int j;
            // 从后向前查找插入位置
            for(j=i-2; v[0]<v[j]; j--) v[j+1] = v[j];
            v[j+1] = v[0];  // 插入到正确位置
        }
        // 输出每趟排序结果
        for(int i=1; i<=n; i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}