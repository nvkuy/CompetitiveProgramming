#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct query {
    int l, r, id;
    query(int le, int ri, int idx) {
        l = le;
        r = ri;
        id = idx;
    }
};

int block_size, tans, n;
vector<int> a, ans, cnt;
vector<query> qrs;

bool cmpMo(query q1, query q2) {
    int bid1 = q1.l / block_size, bid2 = q2.l / block_size;
    if (bid1 == bid2)
        return q1.r < q2.r;
    return bid1 < bid2;
}

void add(int i) {
    if (a[i] > n)
        return;
    if (cnt[a[i]] == a[i])
        tans--;
    if (cnt[a[i]] == a[i] - 1)
        tans++;
    cnt[a[i]]++;
}

void del(int i) {
    if (a[i] > n)
        return;
    if (cnt[a[i]] == a[i])
        tans--;
    if (cnt[a[i]] == a[i] + 1)
        tans++;
    cnt[a[i]]--;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, l, r;
    cin >> n >> q;
    a.resize(n), ans.resize(q), cnt.assign(n + 1, 0), block_size = sqrt(n);
    for (int i = 0;  i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        qrs.push_back(query(l - 1, r - 1, i));
    }
    sort(qrs.begin(), qrs.end(), cmpMo);
    tans = 0, l = 0, r = -1;
    for (int i = 0; i < qrs.size(); i++) {
        query cq = qrs[i];
        while (r > cq.r) {
            del(r);
            r--;
        }
        while (r < cq.r) {
            r++;
            add(r);
        }
        while (l > cq.l) {
            l--;
            add(l);
        }
        while (l < cq.l) {
            del(l);
            l++;
        }
        ans[cq.id] = tans;
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';

    return 0;
}
