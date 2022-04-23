#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool iok;
vector<string> as(4);
string s;
vector<int> dd(4, 0);

void dfs(int j, int u) {
    if (iok || j >= s.length())
        return;
    dd[u] = true;
    for (int i = 0; i < as[u].length(); i++) {
        if (s[j] != as[u][i])
            continue;
        if (j + 1 >= s.length())
            iok = true;
        for (int k = 0; k < 4; k++)
            if (!dd[k])
                dfs(j + 1, k);
        break;
    }
    dd[u] = false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("1.in", "r", stdin);

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < 4; i++)
        getline(cin, as[i]);
    while (n--) {
        getline(cin, s);
        iok = false;
        for (int i = 0; i < 4; i++)
            dfs(0, i);
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
