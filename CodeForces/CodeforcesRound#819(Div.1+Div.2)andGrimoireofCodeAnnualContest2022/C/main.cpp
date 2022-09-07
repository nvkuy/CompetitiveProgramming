#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> par;

int root(int v) {
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void mergeSet(int x, int y) {
    if ((x = root(x)) == (y = root(y)))
        return ;
    if (par[y] < par[x])
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        par.assign(s.length(), -1);
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
                if (i > 0 && s[i - 1] == ')')
                    mergeSet(i, i - 1);
                continue;
            }
            int j = st.top();
            st.pop();
            mergeSet(i, j);
        }
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
            ans += (root(i) == i);
        cout << ans << endl;
    }

    return 0;
}
