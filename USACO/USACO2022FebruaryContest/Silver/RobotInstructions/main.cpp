#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")

vector<pair<int, int>> cors;
vector<map<string, int>> cnt;

struct pos {
    long long xi, yi;
    int ki;
    pos(long long x, long long y, int k) {
        xi = x, yi = y;
        ki = k;
    }
    string toString() {
        return to_string(xi) + '|' + to_string(yi);
    }
};

void bf(int l, int r, vector<pos> &arr) {
    int n = r - l + 1;
    long long xi, yi, fm = (1 << n);
    for (int choose = 0; choose < fm; choose++) {
        bitset<22> bs(choose);
        xi = yi = 0;
        for (int i = l; i <= r; i++) {
            if (bs[i - l]) {
                xi += cors[i].first;
                yi += cors[i].second;
            }
        }
        arr.push_back(pos(xi, yi, bs.count()));
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, x, y;
    cin >> n >> x >> y;
    cors.resize(n);
    for (int i = 0; i < n; i++)
        cin >> cors[i].first >> cors[i].second;
    vector<pos> a, b;
    bf(0, n / 2, a);
    bf(min(n / 2 + 1, n - 1), n - 1, b);
    cnt.resize(22);
    for (int i = 0; i < b.size(); i++)
        cnt[b[i].ki][b[i].toString()]++;
    for (int i = 1; i <= n; i++) {
        long long ans = 0;
        for (int j = 0; j < a.size(); j++) {
            pos tmp = pos(x - a[j].xi, y - a[j].yi, i - a[j].ki);
            if (tmp.ki >= 0)
                ans += cnt[tmp.ki][tmp.toString()];
        }
        cout << ans << '\n';
    }

    return 0;
}
