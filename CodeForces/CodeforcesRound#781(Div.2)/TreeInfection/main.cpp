#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> cnt(n + 1, 0);
        priority_queue<int> rm;
        for (int i = 1; i < n; i++) {
            cin >> ai;
            cnt[ai]++;
        }
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 0)
                rm.push(cnt[i]);
        }
        int time = 0, t2;
        bool needDelRoot = true;
        vector<int> t1;
        while (!rm.empty()) {
            time++;
            t2 = rm.top();
            t2 -= rm.size();
            rm.pop();
            if (t2 > 0)
                t1.push_back(t2);
        }
        for (int i = 0; i < t1.size(); i++)
            rm.push(t1[i]);
        while (!rm.empty()) {
            t1.clear();
            time++;
            if (rm.top() == 1) {
                needDelRoot = false;
                break;
            }
            t2 = rm.top();
            t2--;
            rm.pop();
            rm.push(t2);
            while (!rm.empty()) {
                t2 = rm.top();
                t2--;
                rm.pop();
                if (t2 > 0)
                    t1.push_back(t2);
            }
            for (int i = 0; i < t1.size(); i++)
                rm.push(t1[i]);
        }
        cout << time + needDelRoot << endl;
    }

    return 0;
}
