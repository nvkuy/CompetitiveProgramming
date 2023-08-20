#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

set<int> inf_open, inf_close;
string s;
int n;

void add(int pos) {

    if (pos + 1 < n && s[pos] == s[pos + 1]) {
        if (s[pos] == '(')
            inf_open.insert(pos + 1);
        else
            inf_close.insert(pos + 1);
    }

    if (pos > 0 && s[pos] == s[pos - 1]) {
        if (s[pos] == '(')
            inf_open.insert(pos);
        else
            inf_close.insert(pos);
    }

}

void del(int pos) {

    if (pos + 1 < n && s[pos] == s[pos + 1]) {
        if (s[pos] == '(')
            inf_open.erase(inf_open.find(pos + 1));
        else
            inf_close.erase(inf_close.find(pos + 1));
    }

    if (pos > 0 && s[pos] == s[pos - 1]) {
        if (s[pos] == '(')
            inf_open.erase(inf_open.find(pos));
        else
            inf_close.erase(inf_close.find(pos));
    }
    
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> n >> q;
    cin >> s;

    for (int i = 0; i < n; i++) add(i);

    while (q--) {

        int x;
        cin >> x;
        x--;

        if (n % 2) {
            cout << "NO" << endl;
            continue;
        }

        del(x);
        if (s[x] == ')') s[x] = '(';
        else s[x] = ')';
        add(x);

        // main idea: "((" or "))" cause unbalance and give infinity open or close => keep track pos of that
        bool iok = false;
        if (s[0] == '(' && s[n - 1] == ')') {
            if (inf_close.size() > 0) {
                if (inf_open.size() > 0 && *inf_open.begin() < *inf_close.begin()) { // first "))" need "((" before
                    if (*inf_open.rbegin() < *inf_close.rbegin()) { // last "((" need "))" after
                        iok = true;
                    }
                }
            } else {
                if (inf_open.size() == 0) iok = true; // no "((" or "))"
            }
        }

        cout << (iok ? "YES" : "NO") << endl;

    }

    return 0;
}
