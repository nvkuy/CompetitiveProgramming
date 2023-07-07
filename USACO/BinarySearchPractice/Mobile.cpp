#include <bits/stdc++.h>
using namespace std;
 
const double eps = 1e-4;
pair<long long, long long> cor[1000001];
 
int main() {
 
    int n;
    double len;
    cin >> n >> len;
    for (int i = 0; i < n; i++)
        cin >> cor[i].first >> cor[i].second;
    double l = 0, r = 4e9 + 1, m;
    while (r - l > eps) {
        m = (l + r) / 2;
        double cur_pos = 0;
        for (int i = 0; i < n; i++) {
            if (m < abs(cor[i].second) + eps) continue;
            double dx = sqrt(m * m - cor[i].second * cor[i].second);
            if (cor[i].first - dx < cur_pos + eps) cur_pos = max(cur_pos, cor[i].first + dx);
        }
        if (len < cur_pos + eps)
            r = m;
        else
            l = m + eps;
    }
    cout << setprecision(3) << fixed << r << endl;
 
    return 0;
}