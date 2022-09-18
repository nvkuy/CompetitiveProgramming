#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, w, h, x1, y1, x2, y2, wi, hi;
    cin >> t;
    while (t--) {
        cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> wi >> hi;
        if (x1 >= wi || y1 >= hi || y2 <= h - hi || x2 <= w - wi)
            cout << "0\n";
        else {
            int mx = wi - x1, my = hi - y1, cmx = w - x2, cmy = h - y2, ans = 1e9 + 7;
            if (mx <= cmx)
                ans = min(ans, mx);
            if (my <= cmy)
                ans = min(ans, my);
            mx = x2 - w + wi, my = y2 - h + hi, cmx = x1, cmy = y1;
            if (mx <= cmx)
                ans = min(ans, mx);
            if (my <= cmy)
                ans = min(ans, my);
            if (ans == 1e9 + 7)
                cout << "-1\n";
            else
                cout << ans << endl;
        }
    }

    return 0;
}
