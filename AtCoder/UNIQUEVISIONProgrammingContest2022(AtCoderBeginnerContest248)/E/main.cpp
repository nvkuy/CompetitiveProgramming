#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

pair<long long, long long> getVector(pair<long long, long long> p1, pair<long long, long long> p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}

bool isInLine(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> vec) {
    return ((p1.first - p2.first) * vec.second) == ((p1.second - p2.second) * vec.first);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, nk, ans = 0;
    cin >> n >> nk;
    vector<vector<bool>> dd(n, vector<bool>(n, false));
    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    if (nk == 1) {
        cout << "Infinity";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dd[i][j])
                continue;
            vector<int> ddp;
            ddp.push_back(i);
            ddp.push_back(j);
            pair<long long, long long> vec = getVector(points[i], points[j]);
            for (int k = 0; k < n; k++) {
                if (k != i && k != j && isInLine(points[i], points[k], vec))
                    ddp.push_back(k);
            }
            for (int k = 0; k < ddp.size(); k++) {
                for (int l = k + 1; l < ddp.size(); l++) {
                    dd[ddp[k]][ddp[l]] = true;
                    dd[ddp[l]][ddp[k]] = true;
                }
            }
            if (ddp.size() >= nk)
                ans++;
        }
    }
    cout << ans;

    return 0;
}
