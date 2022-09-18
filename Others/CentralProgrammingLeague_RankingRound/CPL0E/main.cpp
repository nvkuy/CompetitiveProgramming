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

int block_size, tans;
vector<int> a, ans;
vector<query> qrs;
vector<map<int, int>> cnt_block;
map<int, int> cnt;
map<int, int>::iterator it;

bool cmpMo(query q1, query q2) {
    int bid1 = q1.l / block_size, bid2 = q2.l / block_size;
    if (bid1 == bid2)
        return q1.r < q2.r;
    return bid1 < bid2;
}

void add(int val, int num) {
    if (cnt[val] == 2)
        tans--;
    if (cnt[val] + num == 2)
        tans++;
    cnt[val] += num;
}

void del(int val, int num) {
    if (cnt[val] == 2)
        tans--;
    if (cnt[val] - num == 2)
        tans++;
    cnt[val] -= num;
}

void addBlock(int block_id) {
    for (it = cnt_block[id].begin(); it != cnt_block[i].end(); it++)
        add(it->first, it->second);
}

void delBlock(int block_id) {
    for (it = cnt_block[id].begin(); it != cnt_block[i].end(); it++)
        del(it->first, it->second);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    /*
    freopen("test_input.txt", "w", stdout);
    srand(time(NULL));
	int tn = 5e5, tq = tn, maxVal = 1e9;
	cout << tn << ' ' << tq << '\n';
    for (int i = 0; i < tn; i++)
        cout << rand() % maxVal + 1 << ' ';
    cout << '\n';
    for (int i = 0; i < tq; i++) {
        int tl = rand() % maxVal + 1;
        int tr = rand() % (maxVal - tl + 1) + tl;
        cout << tl << ' ' << tr << '\n';
    }
    return 0;
    */

    freopen("test_input.txt", "r", stdin);
    freopen("test_output.txt", "w", stdout);

    int n, q, l, r;
    cin >> n >> q;
    a.resize(n), ans.resize(q), cnt.assign(n + 1, 0), block_size = sqrt(n), cnt_block.resize(block_size + 2);
    for (int i = 0;  i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        qrs.push_back(query(l - 1, r - 1, i));
    }
    sort(qrs.begin(), qrs.end(), cmpMo);
    tans = 0, l = 0, r = 0, cnt[a[0]]++;
    for (int i = 0; i < qrs.size(); i++) {
        query cq = qrs[i];
        while (r > cq.r) {
            if (r / block_size != cq.r / block_size) {
                while (r % block_size > 0) {
                    del(a[r], 1);
                    r--;
                }
                while (r / block_size != cq.r / block_size) {
                    delBlock(r / block_size);
                    r -= block_size;
                }
            }
            del(a[r], 1);
            r--;
        }
        while (r < cq.r) {
            if (r / block_size != cq.r / block_size) {
                while (r % block_size > 0) {
                    r++;
                    add(a[r], 1);
                }
                while (r / block_size != cq.r / block_size) {
                    r +=
                    delBlock(r / block_size);
                    r -= block_size;
                }
            }
            del(r);
            r--;
            //
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
