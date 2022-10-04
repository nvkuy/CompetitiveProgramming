#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

struct ft {
    int kk[22];
};

string hashing(ft &tmp, int k) {
    string rs;
    for (int i = 0; i < k; i++)
        rs += to_string(tmp.kk[i]);
    return rs;
}

struct gs {
    int p1, p2, p3;
};

vector<ft> arr;
vector<gs> group;
map<string, int> dd;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ft tmp;
        for (int j = 0; j < k; j++)
            cin >> tmp.kk[j];
        arr.push_back(tmp);
        dd.insert({hashing(tmp, k), i});
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ft t1;
            for (int l = 0; l < k; l++) {
                if (arr[i].kk[l] == arr[j].kk[l])
                    t1.kk[l] = arr[i].kk[l];
                else
                    t1.kk[l] = 3 - arr[i].kk[l] - arr[j].kk[l];
            }
            auto it = dd.find(hashing(t1, k));
            if (it == dd.end() || it->second <= j)
                continue;
            group.push_back({i, j, it->second});
        }
    }
    int ans = 0;
    for (int i = 0; i < group.size(); i++) {
        for (int j = i + 1; j < group.size(); j++) {
            set<int> tmp;
            tmp.insert(group[i].p1);
            tmp.insert(group[i].p2);
            tmp.insert(group[i].p3);
            tmp.insert(group[j].p1);
            tmp.insert(group[j].p2);
            tmp.insert(group[j].p3);
            if (tmp.size() != 5)
                continue;
            ans++;
            cout << "Match at: ";
            map<int, int> t1;
            t1[group[i].p1]++;
            t1[group[i].p2]++;
            t1[group[i].p3]++;
            t1[group[j].p1]++;
            t1[group[j].p2]++;
            t1[group[j].p3]++;
            for (auto t2 : t1)
                if (t2.second == 2)
                    cout << t2.first << endl;
            cout << group[i].p1 << '|' << group[i].p2 << '|' << group[i].p3 << endl;
            cout << group[j].p1 << '|' << group[j].p2 << '|' << group[j].p3 << endl;
        }
    }
    cout << ans << endl;

    return 0;
}
