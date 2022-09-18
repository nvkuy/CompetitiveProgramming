#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

string s2;
set<string> dd;
long long op = -1;

void dfs(string u, int d) {
    if (op >= 0)
        return;
    dd.insert(u);
    if (u == s2) {
        op = d;
        return;
    }
    swap(u[0], u[2]);
    if (dd.find(u) == dd.end())
        dfs(u, d + 1);
    swap(u[0], u[2]);
    swap(u[2], u[4]);
    if (dd.find(u) == dd.end())
        dfs(u, d + 1);
    swap(u[2], u[4]);
    swap(u[4], u[0]);
    if (dd.find(u) == dd.end())
        dfs(u, d + 1);
    swap(u[0], u[4]);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s1;
    getline(cin, s1);
    getline(cin, s2);
    dfs(s1, 0);
    //cout << op << endl;
    if (op % 2 == 1)
        cout << "No";
    else
        cout << "Yes";

    return 0;
}
