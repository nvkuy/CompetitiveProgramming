#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
1
7 2
4 13 0 0 13 1337 1000000000
*/

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(n), dd(n, false);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < n)
                dd[a[i]] = true;
        }
        int mm = 0, md = 0, tk = k;
        while (mm < n) {
            if (dd[mm])
                mm++;
            else {
                if (tk <= 0)
                    break;
                tk--;
                dd[mm] = true;
            }
        }
        map<int, int> cnt;
        map<int, int>::iterator it;
        for (int i = 0; i < n; i++)
            cnt[a[i]]++;
        md = cnt.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int rm = 0;
        for (it = cnt.begin(); it != cnt.end(); it++) {
            if ((*it).first >= mm)
                pq.push((*it).second);
            else
                rm += ((*it).second - 1);
        }
        while (!pq.empty()) {
            int tmp = pq.top(); pq.pop();
            if (k >= tmp) {
                k -= tmp;
                md += (tmp - 1);
            } else {
                md += k;
                k = 0;
                break;
            }
        }
        md += min(k, rm);
        //cout << md << '|' << mm << endl;
        cout << md - mm << endl;
    }

    return 0;
}
