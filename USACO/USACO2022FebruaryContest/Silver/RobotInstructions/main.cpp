#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> cors;
vector<map<pair<long long, long long>, int>> cnt;

struct pos {
    long long xi, yi;
    int ki;
    pair<long long, long long> getCor() {
        return make_pair(xi, yi);
    }
};

void bf(int l, int r, vector<pos> &arr) {
    int n = r - l + 1;
    long long xi, yi, fm = (1 << n);
    arr.resize(fm);
    for (int choose = 0; choose < fm; choose++) {
        bitset<22> bs(choose);
        xi = yi = 0;
        for (int i = l; i <= r; i++) {
            if (bs[i - l]) {
                xi += cors[i].first;
                yi += cors[i].second;
            }
        }
        arr[choose] = {xi, yi, bs.count()};
    }
}

int main()
{

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
        cnt[b[i].ki][b[i].getCor()]++;
    for (int i = 1; i <= n; i++) {
        long long ans = 0;
        for (int j = 0; j < a.size(); j++) {
            pos tmp = {x - a[j].xi, y - a[j].yi, i - a[j].ki};
            if (tmp.ki >= 0)
                ans += cnt[tmp.ki][tmp.getCor()];
        }
        cout << ans << '\n';
    }

    return 0;
}
