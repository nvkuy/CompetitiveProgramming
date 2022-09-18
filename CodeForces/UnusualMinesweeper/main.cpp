#include <bits/stdc++.h>

using namespace std;

struct cor {
    int x, y, ti;
    cor(int xi, int yi, int tim) {
        x = xi;
        y = yi;
        ti = tim;
    }
};

bool cmp(cor c1, cor c2) {
    if (c1.x == c2.x)
        return c1.y < c2.y;
    return c1.x < c2.x;
}

vector<cor> cors;

int main()
{
    int t, n, k, xi, yi, ti;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        cors.clear();
        //cout << n << " " << k << endl;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &xi, &yi, &ti);
            cors.push_back(cor(xi, yi, ti));
        }
        sort(cors.begin(), cors.end(), cmp);
        for (int i = 0; i < n; i++) {
            //if (cors[])
        }
    }

    return 0;
}
