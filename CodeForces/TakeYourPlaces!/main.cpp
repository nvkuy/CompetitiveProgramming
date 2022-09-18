#include <bits/stdc++.h>

using namespace std;

long long cal(vector<int> &a, int n) {
    long long ans = 0;
    int j = 0;
    for (int i = 1; i < n; i += 2) {
        ans += abs(a[j] - i);
        j++;
    }
    return ans;
}

int main()
{
    int t, n, ai;
    vector<int> ev, od;
    cin >> t;
    while (t--) {
        cin >> n;
        od.clear(); ev.clear();
        for (int i = 0; i < n; i++) {
            cin >> ai;
            if (ai % 2)
                od.push_back(i);
            else
                ev.push_back(i);
        }
        if (abs((int)(od.size() - ev.size())) > 1) {
            cout << "-1\n";
            continue;
        }
        if (od.size() == ev.size())
            cout << min(cal(ev, n), cal(od, n)) << '\n';
        else if (od.size() > ev.size())
            cout << cal(ev, n) << '\n';
        else
            cout << cal(od, n) << '\n';
    }

    return 0;
}
