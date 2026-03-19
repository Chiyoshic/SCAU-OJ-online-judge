#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 单调栈
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> h(n+2);
    stack<int> st;
    st.push(0);

    for(int i=1; i<=n; i++) {
        cin >> h[i];
    }

    long long ans = 0;

    for(int i=1; i<=n+1; i++) {
        while(h[st.top()] > h[i]) {
            int idx = st.top();
            st.pop();

            long long height = h[idx];
            int width = i - st.top() - 1;

            ans = max(ans, width * height);
        }
        st.push(i);
    }

    cout << ans << endl;

    return 0;
}
