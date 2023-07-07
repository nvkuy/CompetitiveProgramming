#include <bits/stdc++.h>
using namespace std;

long long cal(long long i, long long n) {
    long long max_normal_edge = (i * (i - 1LL)) / 2LL;
    long long bridge = n - i;
    long long real_normal_edge = max(min(max_normal_edge, bridge), i - 1);
    if (real_normal_edge > bridge) return 0LL;
    return real_normal_edge + bridge;
}

int main() {

    int q;
    cin >> q;
    while (q--) {
        long long n;
        cin >> n;
        long long l = 1, r = n, ans = 0;
        while (true) {
            if (r - l < 5) {
                int res = l;
                for (int i = l; i <= r; i++)
                    if (cal(res, n) < cal(i, n))
                        res = i;
                ans = res;
                break;
            }
            long long m1 = l + (r - l) / 3, m2 = l + (2 * (r - l) / 3);
            if (cal(m1, n) > cal(m2, n))
                r = m2;
            else
                l = m1;
        }
        cout << cal(ans, n) << endl;
    }

    return 0;
}