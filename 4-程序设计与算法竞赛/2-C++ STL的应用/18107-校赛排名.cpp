#include <vector>
#include <algorithm>
#include <cstdio>  // 用于高性能输入输出(scanf/printf)

using namespace std;

/*
 * 选手结构体定义
 * 存储每位参赛选手的信息，用于排序
 * 成员变量说明:
 *   solve - 解题数量(主要排序依据，降序)
 *   time - 用时分钟数(次要排序依据，升序)
 *   name - 选手姓名(固定长度数组，节省内存)
 *   index - 输入顺序(稳定排序依据，升序)
 * 设计思想:
 *   1. 使用固定长度char数组而非string提高性能
 *   2. 添加index字段实现稳定排序
 *   3. 内存紧凑布局减少缓存未命中
 */
struct Student {
    int solve;      // 解题数量(降序优先)
    int time;       // 用时分钟数(升序次优先)
    char name[21];  // 姓名(固定长度20字符+1终止符)
    int index;      // 输入顺序(稳定排序依据)
};

/*
 * 自定义比较函数
 * 实现多条件排序规则:
 * 1. 解题数量降序(主要)
 * 2. 用时升序(次要)
 * 3. 输入顺序升序(稳定)
 * 算法特点:
 * - 稳定排序: 当解题数和用时相同时保持输入顺序
 * - 高效比较: 先比较主要条件，再比较次要条件
 * 记忆技巧:
 * 解题数(大→小) > 用时(小→大) > 输入顺序(先→后)
 */
bool cmp(const Student &a, const Student &b) {
    if (a.solve != b.solve) return a.solve > b.solve; // 解题数降序
    if (a.time != b.time) return a.time < b.time;     // 用时升序
    return a.index < b.index;                         // 输入顺序升序
}

/*
 * 主函数处理流程
 * 1. 输入处理阶段:
 *    - 使用scanf高效读取大量数据(500000条)
 *    - 为每个选手记录输入顺序(index)
 * 2. 排序阶段:
 *    - 使用STL sort算法配合自定义比较函数
 *    - 时间复杂度: O(n log n)
 * 3. 输出阶段:
 *    - 使用printf高效输出结果
 * 性能优化:
 * - 使用vector预分配内存减少动态扩容
 * - 避免使用string和cin/cout降低IO开销
 */
int main() {
    int n;  // 选手数量
    scanf("%d", &n);  // 读取选手总数

    vector<Student> students;  // 存储所有选手数据
    students.reserve(n);       // 预分配内存提高性能

    // 读取并存储每位选手数据
    for (int i = 0; i < n; ++i) {
        Student s;
        scanf("%d %d %s", &s.solve, &s.time, s.name);
        s.index = i;  // 记录输入顺序
        students.push_back(s);
    }

    // 使用自定义比较函数进行排序
    sort(students.begin(), students.end(), cmp);

    // 输出排序后的选手姓名
    for (const auto &s : students) {
        printf("%s\n", s.name);  // 使用printf提高输出效率
    }

    return 0;
}

/*
Description
校赛结束了，每一个参赛选手由3个数据项构成（通过题数，用时分钟数，姓名），排名按照通过题数排序
通过题数多的排前，同题数的，罚时少的排前。如果题数相同，罚时也相同，而按数据读取的先后排。
给你N个参赛选手的数据，按排序先后，输出姓名



输入格式
第一个数为N，（N<=500000）
此后，每行一个参赛选手的数据，通过题数，用时分钟数，姓名，前两者为整型数，姓名为字符串（不多于20个字符）


输出格式
姓名排名


输入样例
4
3 5 Jon
5 100 Smith
3 5 Tom
6 95 Hel


输出样例
Hel
Smith
Jon
Tom


提示
由于有500000个数据，输入和输出务必使用scanf和printf
*/