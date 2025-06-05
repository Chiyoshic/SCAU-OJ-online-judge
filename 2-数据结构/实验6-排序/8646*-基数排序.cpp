#include <iostream>
#include <vector>
// 基数排序算法实现
// 算法思想：按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位
// 记忆方法："分桶收集" - 按位分配到桶中再收集
using namespace std;

// 数字类：存储数字及其各位数字
class number{
public:
    int val;          // 原始数值
    int length = 0;   // 数字位数
    vector<int> valpos; // 存储各位数字（从低位到高位）

    number(int val){
        this->val = val;
        int t = val;
        // 分解数字的各位数字
        while(t>0){
            this->valpos.push_back(t%10); // 取最低位
            t/=10;                       // 去掉最低位
            this->length++;              // 位数计数
        }
    }

    void printVal(){
        for(int i=length-1; i>=0; i--) cout << this->valpos[i] << " ";
        cout << "length: " << this->length;
        cout << endl;
    }

};

int main(){
    // 输入数据
    vector<number> v;  // 存储所有数字
    int n;            // 数字个数
    cin >> n;
    int maxPos = 1;   // 最大位数
    
    // 读取数字并初始化
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        v.push_back(number(t));
        maxPos = max(maxPos, v[i].length); // 更新最大位数
    }

    // 基数排序主过程
    for(int i=0; i<maxPos; i++){  // 对每一位进行排序
        vector< vector<number> > sheet; // 10个桶(0-9)
        sheet.resize(10);
        
        // 分配过程：将数字放入对应桶中
        for(int j=0; j<n; j++){
            if(i < v[j].length){
                sheet[v[j].valpos[i]].push_back(v[j]); // 按当前位数字放入对应桶
            }else{
                sheet[0].push_back(v[j]); // 位数不足的放入0桶
            }
        }

        // 收集过程：按桶顺序收集数字
        v.clear();
        for(int j=0 ;j<10; j++){
            for(int k=0; k<sheet[j].size(); k++){
                v.push_back(sheet[j][k]); // 从桶中取出数字
            }
        }

        // 输出当前排序结果
        for(auto& thenumber : v){
            printf("%03d ", thenumber.val); // 格式化输出
        }
        cout << endl;
    }




    return 0;
    // 注意：vector会自动释放内存
}