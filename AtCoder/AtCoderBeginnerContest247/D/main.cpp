#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long q, t, x, c;
    deque<pair<int, long long>> dq;
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> x >> c;
            if (dq.empty()) {
                dq.push_front(make_pair(x, c));
                continue;
            }
            pair<int, long long> tmp = dq.front();
            dq.pop_front();
            if (x == tmp.first)
                tmp.second += c;
            dq.push_front(tmp);
            if (x != tmp.first)
                dq.push_front(make_pair(x, c));
        } else {
            cin >> c;
            long long ans = 0;
            while (c > 0) {
                pair<int, long long> t1 = dq.back();
                dq.pop_back();
                long long t2 = min(c, t1.second);
                c -= t2, t1.second -= t2, ans += (t1.first * t2);
                if (t1.second > 0)
                    dq.push_back(t1);
            }
            cout << ans << endl;
        }
    }

    return 0;
}
