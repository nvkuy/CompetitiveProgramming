#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n), b;
    map<string, long long> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int ai = a[i];
        string tmp = "_";
        for (int j = 2; j * j <= ai; j++) {
            int tcnt = 0;
            while (ai % j == 0) {
                tcnt++;
                ai /= j;
            }
            if (tcnt % k > 0)
                tmp += (to_string(j) + "|" + to_string(tcnt % k) + "_");
        }
        if (ai > 1) tmp += (to_string(ai) + "|" + to_string(1) + "_");
        cnt[tmp]++;
        if (cnt[tmp] == 1)
            b.push_back(a[i]);
    }

    // for (auto tt : cnt)
    //     cout << tt.first << ' ' << tt.second << endl;

    long long ans = 0;
    for (int t3 : b) {
        int ai = t3;
        string t1 = "_", t2 = "_";
        for (int j = 2; j * j <= ai; j++) {
            int tcnt = 0;
            while (ai % j == 0) {
                tcnt++;
                ai /= j;
            }
            if (tcnt % k > 0)
                t1 += (to_string(j) + "|" + to_string(tcnt % k) + "_");
            if ((k - (tcnt % k)) % k > 0)
                t2 += (to_string(j) + "|" + to_string((k - (tcnt % k)) % k) + "_");
        }
        if (ai > 1) {
            t1 += (to_string(ai) + "|" + to_string(1) + "_");
            t2 += (to_string(ai) + "|" + to_string(k - 1) + "_");
        }
        if (t1 == t2)
            ans += cnt[t1] * (cnt[t1] - 1);
        else
            ans += cnt[t1] * cnt[t2];
    }

    assert(ans % 2 == 0);
    ans /= 2;
    cout << ans << endl;

    return 0;
}