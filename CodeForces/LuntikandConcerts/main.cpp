#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

vector<long long> rm;
int ans;

void cal(int c1, int c2, int i) {
    if (i < 0) {
        ans = min(ans, abs(c1 - c2));
        return;
    }
    cal(c1 + rm[i], c2, i - 1);
    cal(c1, c2 + rm[i], i - 1);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, a, b, c, tmp;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        ans = 1e9;
        rm.clear();
        tmp = min(a, 3);
        if (tmp == 3 && (a - 3) % 2 > 0)
            tmp++;
        for (int i = 1; i <= tmp; i++)
            rm.push_back(1);
        tmp = min(b, 2);
        if (tmp == 2 && (b - 2) % 2 > 0)
            tmp++;
        for (int i = 1; i <= tmp; i++)
            rm.push_back(2);
        tmp = min(c, 1);
        if (tmp == 1 && (c - 1) % 2 > 0)
            tmp++;
        for (int i = 1; i <= tmp; i++)
            rm.push_back(3);
        cal(0, 0, rm.size() - 1);
        cout << ans << endl;
    }

    return 0;
}
