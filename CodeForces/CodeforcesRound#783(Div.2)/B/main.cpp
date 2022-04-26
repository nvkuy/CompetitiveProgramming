#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        deque<int> dq;
        while (!a.empty()) {
            if (dq.empty() || dq.front() > dq.back())
                dq.push_front(a.back());
            else
                dq.push_back(a.back());
            a.pop_back();
        }
        long long need = 0;
        for (int i = 1; i < dq.size(); i++)
            need += max(dq[i - 1], dq[i]);
        need += (max(dq.front(), dq.back()) + n);
        cout << ((need > m) ? "NO" : "YES") << endl;
    }

    return 0;
}
