#include <iostream>
#include <vector>

using namespace std;

// 使用双指针法将负数移到前面，正数移到后面
void partitionArray(vector<int>& nums) {
    int left = 0;                  // 左指针，初始指向数组的第一个元素
    int right = nums.size() - 1;   // 右指针，初始指向数组的最后一个元素

    while (left <= right) {
        // 左指针向右移动，直到找到一个正数
        while (left <= right && nums[left] < 0) {
            left++;
        }
        // 右指针向左移动，直到找到一个负数
        while (left <= right && nums[right] > 0) {
            right--;
        }
        // 如果左指针仍然小于等于右指针，交换两个元素
        if (left <= right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int T;
    cin >> T;  // 读取数据组数

    while (T--) {
        int n;
        cin >> n;  // 读取数组大小

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];  // 读取数组元素
        }

        // 调用双指针法进行分区
        partitionArray(nums);

        // 输出结果
        for (int i = 0; i < n; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
Description
一个数组只包含正负整数，请使用一个O（n）级别的算法对其进行排序。
只需将负数全部放前面，正数全部放后面即可，无需进行严格排序。
此题目必须使用双指针法才能通过，
双指针，指的是在遍历对象的过程中，不是普通的使用单个指针进行访问，
而是使用两个相反方向（对撞指针）的指针进行扫描，从而达到相应的目的。
具体算法如下：
定义两个指针：i=1，j=n
（1）i指针从左至右遍历，当碰到不满足条件的元素（正数），我们暂停i 移动
（2）j指针从右至左遍历，当碰到不满足条件的元素（负数），我们暂停 j 移动
（3）交换两个指针i和j指向的元素
（4）重复 1，2，3 步骤，直到i和j相遇


题目包含T组数据。



输入格式
第一行一个整数T,表示数据的组数。（1<=T<=10）
下面共2*T行，每两行为一组数据。
第i组数组的第一行为整数n，（1<=n<=100000）表示数组的大小，第二行为n个整数。


输出格式
共T行，排序后的T组数据。


输入样例
2
3
1 -1 2
4
-1 2 3 -4


输出样例
-1 1 2
-1 -4 3 2
*/