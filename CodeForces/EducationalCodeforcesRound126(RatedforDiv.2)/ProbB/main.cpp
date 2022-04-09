#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int minOp(int ai) {
    if (ai == 0)
        return 0;
    int ans = 15, t1, t2;
    for (int i = ai; i <= ai + 15; i++) {
        t1 = i, t2 = 0;
        while (t1 % 2 == 0) {
            t1 /= 2;
            t2++;
        }
        ans = min(ans, 15 - t2 + i - ai);
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << minOp(a[i]) << ' ';

    return 0;
}
