#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int r, c;
string nut;
vector<string> a;
vector<vector<int>> dd;

bool isValid(int row, int pos) {
    for (int i = 0; i < c; i++)
        if (a[row][i] == '1' && nut[(i + pos) % c] == '1')
            return false;
    return true;
}

void dfs(int row, int pos) {
    dd[row][pos] = 1;
    if (row - 1 >= 0)
        if (isValid(row - 1, pos) && !dd[row - 1][pos])
            dfs(row - 1, pos);
    if (row + 1 < r)
        if (isValid(row + 1, pos) && !dd[row + 1][pos])
            dfs(row + 1, pos);
    if (isValid(row, (pos + 1) % c) && !dd[row][(pos + 1) % c])
        dfs(row, (pos + 1) % c);
    if (isValid(row, (pos - 1 + c) % c) && !dd[row][(pos - 1 + c) % c])
        dfs(row, (pos - 1 + c) % c);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    cin >> nut;
    a.resize(r);
    dd.assign(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        cin >> a[i];
    for (int i = 0; i < c; i++) {
        if (isValid(0, i) && !dd[0][i])
            dfs(0, i);
    }
    bool hasAns = false;
    for (int i = 0; i < c; i++) hasAns |= dd[r - 1][i];
    dd.assign(r, vector<int>(c, 0));
    reverse(nut.begin(), nut.end());
    for (int i = 0; i < c; i++) {
        if (isValid(0, i) && !dd[0][i])
            dfs(0, i);
    }
    for (int i = 0; i < c; i++) hasAns |= dd[r - 1][i];
    cout << (hasAns ? "Y" : "N") << endl;

    return 0;
}
