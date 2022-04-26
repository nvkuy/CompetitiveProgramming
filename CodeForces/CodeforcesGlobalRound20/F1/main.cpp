#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> c(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c[a[i]].push_back(i);
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i <= n; i++) {
            if (c[i].size() > 0) {
                pq.push({c[i].size(), i});
            }
        }
        vector<int> b = a;
        vector<pair<int, int>> instructions;
        while (pq.size() > 1) {
            pair<int, int> p1 = pq.top(); pq.pop();
            pair<int, int> p2 = pq.top(); pq.pop();
            instructions.push_back({p1.second, p2.second});
            p1.first--, p2.first--;
            if (p1.first > 0)
                pq.push(p1);
            if (p2.first > 0)
                pq.push(p2);
        }
        for (int i = 0; i < instructions.size(); i++) {
            pair<int, int> tmp = instructions[i];
            swap(b[c[tmp.first].back()], b[c[tmp.second].back()]);
            c[tmp.first].pop_back(), c[tmp.second].pop_back();
        }
        pair<int, int> tmp = {0, 0};
        if (pq.size() > 0)
            tmp = pq.top();
        for (int i = 0; i < n; i++) {
            if (tmp.first <= 0)
                break;
            if (a[i] != tmp.second && b[i] != tmp.second) {
                int p = c[tmp.second].back(); c[tmp.second].pop_back();
                tmp.first--;
                swap(b[i], b[p]);
            }
        }
        for (int i = 0; i < n; i++)
            cout << b[i] << ' ';
        cout << endl;
    }

    return 0;
}
