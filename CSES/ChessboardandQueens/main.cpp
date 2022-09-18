#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int ans = 0, n = 8;
vector<vector<bool>> cb;

void make(int qi, vector<bool> ddc, vector<bool> dddr, vector<bool> dddl) {
    if (qi < 1) {
        ans++;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (ddc[j] | dddr[j - qi + n] | cb[qi - 1][j] | dddl[qi + j - 1])
            continue;
        //cout << qi << ':' << qi - 1 << '-' << j << endl;
        ddc[j] = dddr[j - qi + n] = dddl[qi + j - 1] = true;
        make(qi - 1, ddc, dddr, dddl);
        ddc[j] = dddr[j - qi + n] = dddl[qi + j - 1] = false;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cb.assign(n, vector<bool>(n, false));
    vector<bool> ddc(n, false), dddr(2 * n + 1, false), dddl(2 * n + 1, false);

    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c != '.')
                cb[i][j] = true;
        }
    }
    make(8, ddc, dddr, dddl);
    cout << ans;

    return 0;
}
