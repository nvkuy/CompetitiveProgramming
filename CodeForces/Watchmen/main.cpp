#include <bits/stdc++.h>

using namespace std;

struct cor{
    long long x, y;
    cor (long long xi, long long yi) {
        x = xi;
        y = yi;
    }
};

vector<cor> corx, cory;

bool cmpx(cor c1, cor c2) {
    if (c1.x == c2.x)
        return c1.y > c2.y;
    return c1.x > c2.x;
}

bool cmpy(cor c1, cor c2) {
    if (c1.y == c2.y)
        return c1.x > c2.x;
    return c1.y > c2.y;
}

int main()
{

    long long n, xi, yi;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> xi >> yi;
        corx.push_back(cor(xi, yi));
        cory.push_back(cor(xi, yi));
    }
    sort(corx.begin(), corx.begin() + n, cmpx);
    sort(cory.begin(), cory.begin() + n, cmpy);
    long long ans = 0;
    long long curx = corx[0].x, cury = cory[0].y, cx = 0, cy = 0;
    for (long long i = 1; i < n; i++) {
        if (curx == corx[i].x) {
            cx++;
            ans += cx;
        } else {
            cx = 0;
            curx = corx[i].x;
        }
    }
    curx = cory[0].x;
    long long ct = 0, tr = 0;
    for (long long i = 1; i < n; i++) {
        if (cury == cory[i].y) {
            if (cory[i].x == curx) {
                ct++;
                tr += ct;
            } else
                ct = 0;
            cy++;
            ans += cy;
        } else {
            cy = 0;
            cury = cory[i].y;
            ct = 0;
        }
        curx = cory[i].x;
    }
    cout << (ans - tr);

    return 0;
}
