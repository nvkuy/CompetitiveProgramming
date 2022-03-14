#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int w, h;
vector<vector<bool>> c;

bool check(int x, int y) {
    int mx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, my[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    for (int i = 0; i < 8; i++) {
        if (x + mx[i] < 0 || x + mx[i] >= h || y + my[i] < 0 || y + my[i] >= w)
            continue;
        if (c[x + mx[i]][y + my[i]])
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> h >> w;
        c.assign(h, vector<bool>(w, false));
        for (int i = 0; i < w; i++) {
            if (check(0, i))
                c[0][i] = true;
        }
        for (int i = 1; i < h; i++) {
            if (check(i, w - 1))
                c[i][w - 1] = true;
        }
        for (int i = w - 2; i >= 0; i--) {
            if (check(h - 1, i))
                c[h - 1][i] = true;
        }
        for (int i = h - 2; i >= 1; i--) {
            if (check(i, 0))
                c[i][0] = true;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                cout << c[i][j];
            cout << endl;
        }
    }

    return 0;
}
