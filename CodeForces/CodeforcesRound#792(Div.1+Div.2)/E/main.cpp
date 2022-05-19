#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n), dd(n, false);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < n)
                dd[a[i]] = true;
        }
        int mm = 0;
        while (mm < n) {
            if (dd[mm])
                mm++;
            else {
                if (k <= 0)
                    break;
                k--;
                dd[mm] = true;
            }
        }
        priority_queue<pair<int, int>> pq;
        map<int, int> cnt;
        map<int, int>::iterator it;
        for (int i = 0; i < n; i++)
            cnt[a[i]]++;
        for (it = cnt.begin(); it != cnt.end(); it++) {
            pair<int, int> tmp = (*it);
            if ((*it).first < mm)
                tmp.second--;
            if (tmp.second <= 0)
                continue;
            pq.push(tmp);
        }

    }

    return 0;
}
