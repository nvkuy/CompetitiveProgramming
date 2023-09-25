#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n), l(n), r(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() > 0 && a[st.top()] <= a[i])
                st.pop();
            int pos = 0;
            if (st.size() > 0) pos = st.top() + 1;
            l[i] = i - pos + 1;
            st.push(i);
        }
        while (st.size() > 0) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 0 && a[st.top()] >= a[i])
                st.pop();
            int pos = n - 1;
            if (st.size() > 0) pos = st.top() - 1;
            r[i] = pos - i;
            st.push(i);
        }
        long long ans = 0;
        for (long long i = 0; i < n; i++) {
            ans -= l[i] * r[i];
            ans += i * (i + 1) / 2;
        }
        cout << ans << endl;
    }

    return 0;
}
