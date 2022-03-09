#include <bits/stdc++.h>

using namespace std;

struct point {
    int wi, xi, id;
    point(int weight, int cor, int indi) {
        wi = weight;
        xi = cor;
        id = indi;
    }
};

bool compW(point p1, point p2) {
    return p1.wi < p2.wi;
}

bool compX(point p1, point p2) {
    return p1.xi < p2.xi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m, sw, x, w;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<point> ps, ans;
        for (int i = 1; i <= m; i++) {
            cin >> x >> w;
            ps.push_back(point(w, x, i));
        }
        sort(ps.begin(), ps.end(), compW);
        sw = 0;
        for (int i = 0; i < 2 * n; i++) {
            ans.push_back(ps[i]);
            sw += ps[i].wi;
        }
        sort(ans.begin(), ans.end(), compX);
        cout << sw << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i].id << ' ' << ans[2 * n - i - 1].id << endl;
    }

    return 0;
}
