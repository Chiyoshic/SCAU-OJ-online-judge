#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;


int main(){
    int n, i;
    cin >> n;
    double WaitingTime = 0, AllTime = 0;
    i = n;
    int Client;
    double Time;
    while(i--){
        cin >> Client >> Time;
        if(AllTime!=0){
            if(AllTime >= Client){
                WaitingTime += (AllTime - Client);
                AllTime += Time;
            }else{
                AllTime += (Client-AllTime+Time);
            }

        }else{
            AllTime += Time+Client;
        }

        //cout << "in " << n-i << " Waiting is " << WaitingTime << endl;
    }

    cout << fixed << setprecision(2) << WaitingTime/n << endl;
    return 0;
}

/*
某银行有一个客户办理业务站，在一天内随机地有客户到达，设每位客户的业务办理时间是某个范围内的值。设只有一个窗口，一位业务人员，要求程序模拟统计在
一天时间内，所有客户的平均等待时间。模拟数据按客户到达的先后顺序依次由键盘输入，对应每位客户有两个数据，到达时刻和需要办理业务的时间。



输入格式
第一行：一天内的客户总人数n
第二行：第一个客户的到达时刻和需要办理业务的时间
第三行：第二个客户的到达时刻和需要办理业务的时间
……
第n行：第n - 1个客户的到达时刻和需要办理业务的时间
第n + 1行：第n 个客户的到达时刻和需要办理业务的时间


输出格式
第一行：所有客户的平均等待时间（精确到小数点后2位）


输入样例
3
1 3
2 1
3 5


输出样例
1.33


作者 yqm*/