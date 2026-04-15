#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

using ll = long long;

ll resol[10001][15];
ll twoPow[15];

ll findSpel(ll cur) {
    for(int i=14; i>=0; i--) {
        if(twoPow[i] <= cur) {
            return i;
        }
    }
}

// 递归深度过深

// ll devide(ll cur, ll spcl) {
//     if(spcl == 0) return 1;
//     if(resol[cur][spcl] != -1) return resol[cur][spcl];
//     ll ret = 0;

//     for(int i=0; i <= spcl; i++) {
//         ll pro = cur - twoPow[i];
//         ret += resol[pro][i] != -1 ? resol[pro][i] : devide(pro, i);
//     }

//     if(resol[cur][spcl] == -1) resol[cur][spcl] = ret;
//     return ret;
// }

int main() {
    memset(resol, -1, sizeof(resol));
    twoPow[0] = 1;
    for(int i=1; i < 15; i++) twoPow[i] = 2 * twoPow[i-1];

    ll n;
    cin >> n;
    ll spcl = findSpel(n);

    for(int i=0; i<=n; i++) resol[i][0] = 1;
    for(int i=0; i<15; i++) resol[0][i] = 1;

    for (int cur = 1; cur <= 10000; cur++) {
        for (int s = 1; s <= 14; s++) {
            ll sum = 0;
            for (int i = 0; i <= s; i++) {
                if (twoPow[i] <= cur) {
                    sum = (sum + resol[cur - twoPow[i]][i]) % 1000000000;
                }
            }
            resol[cur][s] = sum;
        }
    }

    cout << resol[n][spcl] << endl;

    return 0;
}