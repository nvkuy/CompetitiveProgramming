#include <bits/stdc++.h>

using namespace std;

struct pt {
    long long x1, y1;
    long long x2, y2;
    int co;
    pt (long long x1i, long long y1i, long long x2i, long long y2i, int ci) {
        x1 = x1i;
        x2 = x2i;
        y1 = y1i;
        y2 = y2i;
        co = ci;
    }
};

bool col(pt p1, pt p2) {
    if (p1.x1 <= p2.x1 && p1.y1 >= p2.y1 && p1.x2 >= p2.x2 && p1.y2 <= p2.y2)
        return true;
    return false;
}

vector<pt> pts;
int dc[4004];

int main()
{
    int n, ans = 0, x1i, y1i, x2i, y2i, ci;
    memset(dc, 0, sizeof(dc));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1i >> y1i >> x2i >> y2i >> ci;
        //ptt = pt(x1i, y1i, x2i, y2i, ci);
        if (pts.empty()) {
            pts.push_back(pt(x1i, y1i, x2i, y2i, ci));
            if (dc[ci] <= 0)
                ans++;
            dc[ci]++;
            continue;
        }
        for (int i = (pts.size() - 1); i >= 0; i--) {
            if (col(pt(x1i, y1i, x2i, y2i, ci), pts[i])) {
                dc[pts[i].co]--;
                if (dc[pts[i].co] <= 0)
                    ans--;
                pts.erase(pts.begin() + i);
            }
        }
        pts.push_back(pt(x1i, y1i, x2i, y2i, ci));
        if (dc[ci] <= 0)
            ans++;
        dc[ci]++;
    }
    cout << ans;

    return 0;
}
