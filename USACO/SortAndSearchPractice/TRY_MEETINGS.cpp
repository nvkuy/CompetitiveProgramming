#include <bits/stdc++.h>
using namespace std;

struct cow {
    int w, x, d;
};

bool cmp(const cow &c1, const cow &c2) {
    return c1.x < c2.x;
}

int main() {

    if (fopen("meetings.in", "r")) {
        freopen("meetings.in", "r", stdin);
        freopen("meetings.out", "w", stdout);
    }
    
    int n, l, out_left = 0;
    cin >> n >> l;
    vector<cow> cows(n);
    vector<int> goLeft, goRight;
    for (int i = 0; i < n; i++)
        cin >> cows[i].w >> cows[i].x >> cows[i].d;
    sort(cows.begin(), cows.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (cows[i].d < 0) {
            out_left++;
            goLeft.push_back(cows[i].x);
        } else
            goRight.push_back(cows[i].x);
    }
    long long sum_weight = 0;
    for (auto c : cows) sum_weight += c.w;
    int time_stop = 0;
    vector<pair<int, int>> time_weight;
    for (int i = 0; i < out_left; i++)
        time_weight.push_back({goLeft[i], cows[i].w});
    for (int i = out_left; i < n; i++)
        time_weight.push_back({l - goRight[i - out_left], cows[i].w});
    sort(time_weight.begin(), time_weight.end());
    long long cur_weight = 0;
    for (auto p : time_weight) {
        cur_weight += p.second;
        if (cur_weight * 2LL >= sum_weight) {
            time_stop = p.first;
            break;
        }
    }
    vector<int> all;
    map<int, int> compressFunc;
    for (auto c : cows) {
        all.push_back(c.x);
        all.push_back(c.x + c.d * time_stop * 2);
    }
    all.push_back(l - 1);
    all.push_back(1);
    sort(all.begin(), all.end());
    int tmp = 1;
    for (int num : all) {
        if (compressFunc[num] == 0)
            compressFunc[num] = tmp++;
    }
    vector<int> psL(tmp + 1, 0), psR = psL;
    for (auto c : cows) {
        if (c.d < 0)
            psL[compressFunc[c.x]]++;
        else
            psR[compressFunc[c.x]]++;
    }
    for (int i = 1; i <= tmp; i++) {
        psL[i] += psL[i - 1];
        psR[i] += psR[i - 1];
    }
    long long ans = 0;
    for (auto c : cows) {
        if (c.d < 0) {
            int fp = c.x, lp = max(1, c.x + c.d * time_stop * 2);
            ans += psR[compressFunc[fp]] - psR[compressFunc[lp] - 1];
        } else {
            int fp = c.x, lp = min(l - 1, c.x + c.d * time_stop * 2);
 