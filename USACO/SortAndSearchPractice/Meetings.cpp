#include <bits/stdc++.h>
using namespace std;

struct cow {
    int w, x, d;
};

int main() {

    if (fopen("meetings.in", "r")) {
        freopen("meetings.in", "r", stdin);
        freopen("meetings.out", "w", stdout);
    }
    
    int n, l;
    cin >> n >> l;
    vector<cow> a(n);
    vector<pair<int, int>> stop_time(n, {1e9, 1e9});
    set<pair<int, int>> toLeft, toRight, t1, t2;
    for (int i = 0; i < n; i++) {
        cin >> a[i].w >> a[i].x >> a[i].d;
        if (a[i].d < 0)
            toLeft.insert({a[i].x, i});
        else
            toRight.insert({a[i].x, i});
    }
    t1 = toLeft, t2 = toRight;
    for (auto c : toRight) {
        auto it = t1.lower_bound(c);
        int need_time = 1e9;
        if (it != t1.end()) {
            need_time = it->first;
            t1.erase(it);
        } else
            need_time = l - c.first;
        stop_time[c.second] = {need_time, c.second};
    }
    for (auto c : toLeft) {
        auto it = t2.lower_bound(c);
        int need_time = 1e9;
        if (it != t2.end() && it != t2.begin()) {
            it--;
            need_time = l - it->first;
            t2.erase(it);
        } else
            need_time = c.first;
        stop_time[c.second] = {need_time, c.second};
    }
    sort(stop_time.begin(), stop_time.end());
    long long sum_weight = 0, cur_weight = 0;
    for (auto c : a) sum_weight += c.w;
    int time_stop = 0;
    for (auto t : stop_time) {
        cur_weight += a[t.second].w;
        if (cur_weight * 2LL >= sum_weight) {
            time_stop = t.first;
            break;
        }
    }
    vector<int> all;
    map<int, int> compressFunc;
    for (auto c : a) {
        all.push_back(c.x);
        all.push_back(c.x + c.d * time_stop);
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
    for (auto c : a) {
        if (c.d < 0) {
            psL[compressFunc[c.x]]++;
            int tt = c.x + c.d * time_stop;
            if (tt > 0)
                psL[compressFunc[tt]]++;
        } else {
            psR[compressFunc[c.x]]++;
            int tt = c.x + c.d * time_stop;
            if (tt < l)
                psR[compressFunc[tt]]++;
        }
    }
    for (int i = 1; i <= tmp; i++) {
        psL[i] += psL[i - 1];
        psR[i] += psR[i - 1];
    }
    long long ans = 0;
    for (auto c : a) {
        if (c.d < 0) {
            int fp = c.x, lp = max(1, c.x + c.d * time_stop);
            ans += psR[compressFunc[fp]] - psR[compressFunc[lp] - 1];
            auto it = toRight.lower_bound({c.x + c.d * time_stop, 0});
            if (it != toRight.end() && it->first == c.x + c.d * time_stop)
                ans--;
        } else {
            int fp = c.x, lp = min(l - 1, c.x + c.d * time_stop);
            ans += psL[compressFunc[lp]] - psL[compressFunc[fp] - 1]; 
            auto it = toLeft.lower_bound({c.x + c.d * time_stop, 0});
            if (it != toLeft.end() && it->first == c.x + c.d * time_stop)
                ans--;
        }
    }
    cout << ans / 2 << endl;
    // cout << time_stop << endl;
    // for (auto c : stop_time)
    //     cout << c.first << '|' << c.second << endl;
    
    return 0;
}