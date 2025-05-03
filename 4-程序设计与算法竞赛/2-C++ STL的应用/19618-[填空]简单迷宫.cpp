#include <iostream>  // 使用标准输入输出流
#include <queue>    // 使用队列数据结构
using namespace std;

/*
 * 位置结构体
 * 用于存储迷宫中的位置坐标和步数
 * r: 行坐标(row)
 * c: 列坐标(column)
 * s: 从起点到该位置的步数(step)
 */
typedef struct{
	int r; 
	int c; 
	int s; 
}LOC;
// 全局变量
int sr, sc;      // 起点坐标(start row, start column)
int dr, dc;      // 终点坐标(destination row, destination column)
// 方向数组: 下、右、上、左
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
char d[100][100]; // 迷宫地图(0可通过，1为墙)
/*
 * BFS迷宫求解函数
 * 算法思想:
 * 1. 使用广度优先搜索(BFS)保证找到最短路径
 * 2. 使用队列实现BFS，按层扩展搜索
 * 3. 访问标记避免重复访问
 * 常见错误:
 * 1. 忘记标记已访问位置导致无限循环
 * 2. 边界检查不完整导致数组越界
 * 3. 步数更新不正确
 */
void solve(){
	int m, n;      // 迷宫的行数和列数
	int nr, nc;    // 新位置的行列坐标(new row, new column)
	queue<LOC> q;  // BFS队列

	// 输入迷宫尺寸
	scanf("%d%d", &m, &n);
	// 输入迷宫地图
	for(int i = 0; i < m; i++) scanf("%s", d[i]);
	// 输入起点和终点坐标
	scanf("%d%d%d%d", &sr, &sc, &dr, &dc);

	// 初始化: 将起点加入队列
	LOC first = {sr, sc, 0};
	q.push(first);

	// BFS主循环
	while(!q.empty()) {

//-------------该行开始是填空的内容--------------
		// 取出队首元素
		LOC curr = q.front();
		q.pop();

		// 检查当前位置是否可通行(避免重复处理)
		if (d[curr.r][curr.c] != '0') {
			continue;  // 已访问过或是墙，跳过
		}

		// 标记当前位置为已访问
		// 记忆技巧: 访问标记放在这里可以确保每个位置只处理一次
		d[curr.r][curr.c] = '1';

		// 检查是否到达终点
		if(curr.r == dr && curr.c == dc) {
			printf("%d\n", curr.s);  // 输出最短步数
			return;  // 找到解立即返回
		}

		// 向四个方向扩展
		for(int j = 0; j < 4; j++) {
			nr = curr.r + dir[j][0];  // 计算新位置行坐标
			nc = curr.c + dir[j][1];  // 计算新位置列坐标

			// 边界检查和新位置可通行检查
			if(nr >= 0 && nr < m && nc >= 0 && nc < n && d[nr][nc] == '0') {
				// 合法新位置，步数+1后加入队列
				LOC next = {nr, nc, curr.s + 1};
				q.push(next);
			}
		}
//-------------该行之上是填空的内容--------------

	}
		// 队列为空仍未找到终点，输出无解
	printf("die\n");

}
/*
 * 主函数
 * 处理多组测试用例
 */
int main(){
	int n;  // 测试用例数量
	scanf("%d", &n);
	while(n--) {
		solve();  // 处理每个迷宫
	}
	return 0;
}

/*
Description
有一个N*M(N,M<=10)的格子迷宫，1代表该格子为墙，不能通过，0代表可以通过，人在迷宫中可以尝试上下左右四个方向移动。
现在给定一个迷宫，以及起点和终点，问最少多少步可以走出迷宫。如果不能走出迷宫输出“die”。
请填空完成程序：

#include <stdio.h>
#include <queue>
using namespace std;
typedef struct{
    int r; // row
    int c; // column
    int s; // step
}LOC;
// 全局变量
int sr, sc;      // 起点坐标(start row, start column)
int dr, dc;      // 终点坐标(destination row, destination column)
// 方向数组: 下、右、上、左
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
char d[100][100]; // 迷宫地图(0可通过，1为墙)
void solve(){
    int m,n,i,nr,nc;
    queue<LOC> q;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++) scanf("%s",d[i]);
    scanf("%d%d%d%d",&sr,&sc,&dr,&dc);
    LOC first={sr,sc,0};
    q.push(first);
    while(!q.empty()) {
_______________________
    }
    	// 队列为空仍未找到终点，输出无解
	printf("die\n");

}
int main(){
    int n;
    scanf("%d",&n);
    while(n--) solve();
}


输入格式
该程序为多CASE，第1行为CASE的数量
每一个CASE，第1行为两个数N（行）和M（列）
然后N行每行M个数，之后是起点坐标和终点坐标sc(行) sr(列) ec(行) er(列)


输出格式
如题


输入样例
2
4 3
011
000
110
110
0 0 3 2
2 2
01
10
0 0 1 1


输出样例
5
die

*/