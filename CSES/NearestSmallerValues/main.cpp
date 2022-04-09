#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ai;
    cin >> n;
    stack<pair<int, int>> st;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> ai;
        while (!st.empty() && st.top().first >= ai)
            st.pop();
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top().second;
        st.push(make_pair(ai, i));
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << ' ';

    return 0;
}
