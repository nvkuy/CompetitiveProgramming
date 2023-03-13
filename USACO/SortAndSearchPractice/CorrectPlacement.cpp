#include <bits/stdc++.h>
using namespace std;

struct people {
    int id, w, h;
};

bool cmpFirst(const people &p1, const people &p2) {
    return p1.w < p2.w;
}

void cal(int n, vector<int> &ans, vector<people> &pp, vector<people> &tpp) {
    pair<int, int> smallest = {1e9 + 7, 1e9 + 7};
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && tpp[j].w < pp[i].w) {
            if (tpp[j].h < smallest.first)
                smallest = {tpp[j].h, tpp[j].id};
            j++;
            continue;
        }
        if (ans[pp[i].id] != -1 || pp[i].h <= smallest.first)
            continue;
        ans[pp[i].id] = smallest.second;
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<people> pp(n);
        for (int i = 0; i < n; i++) {
            cin >> pp[i].h >> pp[i].w;
            pp[i].id = i + 1;
        }
        vector<int> ans(n + 1, -1);
        sort(pp.begin(), pp.end(), cmpFirst);
        vector<people> tpp = pp;
        cal(n, ans, pp, tpp);
        for (int i = 0; i < n; i++)
            swap(pp[i].w, pp[i].h);
        sort(pp.begin(), pp.end(), cmpFirst);
        cal(n, ans, pp, tpp);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}