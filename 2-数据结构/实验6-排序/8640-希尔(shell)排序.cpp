#include <iostream>
#include <vector>
using namespace std;

/* 希尔排序算法实现
 * 算法思想：通过增量分组进行插入排序，逐步缩小增量直至1
 * 记忆方法：分组插入排序，增量逐步缩小（通常n/2递减）
 */

int main(){
    // 输入数据
    int n;  // 元素个数
    cin >> n;
    vector<int> v(n+1, 0);  // 使用v[0]作为哨兵
    for(int i=1; i<=n; i++){
        cin >> v[i];  // 输入待排序元素
    }
    // 希尔排序核心算法
    for(int inc = n/2; inc>0; inc/=2){  // 增量序列，初始为n/2，每次减半
        for(int f=1; f<=inc; f++){  // 对每个分组进行插入排序
            for(int i=f+inc; i<v.size(); i+=inc){  // 组内插入排序
                if(v[i] < v[i-inc]){  // 当前元素小于前一个元素时才需要插入
                    v[0] = v[i];  // 设置哨兵
                    int j;
                    // 组内元素后移
                    for(j=i-inc; j>0 && v[0]<v[j]; j-=inc) v[j+inc] = v[j];
                    v[j+inc] = v[0];  // 插入到正确位置
                }
            }
        }
        // 输出每趟排序结果
        for(int i=1; i<=n; i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}