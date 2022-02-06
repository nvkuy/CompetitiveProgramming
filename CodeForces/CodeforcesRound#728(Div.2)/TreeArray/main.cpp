#include <bits/stdc++.h>

using namespace std;

long long modExpo(long long x, long long n, long long M){
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return modExpo((x * x) % M, n / 2, M);
    else
        return (x * modExpo((x * x) % M, (n - 1) / 2, M)) % M;
}

int modInvFE(int A,int M) {
    return modExpo(A,M-2,M);
}

long long n, mod = 1e9 + 7;
long long calInv(vector<int> a) {
    long long ans = 0LL;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] > a[i])
                ans++;
    return ans;
}

vector<bool> dd;
vector<vector<int>> c;
long long dfs(int u, vector<int> a) {
    if (a.size() == n)
        return calInv(a);
    long long ans = 0LL, j = modInvFE(c[u].size(), mod);
    for (int i = 0; i < c[u].size(); i++) {
        if (!dd[c[u][i]]) {
            a.push_back(c[u][i]);
            dd[c[u][i]] = true;
            ans = (ans + ((j * dfs(c[u][i], a)) % mod)) % mod;
            a.pop_back();
            dd[c[u][i]] = false;
        }
    }
    //cout << u << ':' << ans << endl;
    return ans;
}

int main()
{
    int u, v;
    cin >> n;
    c.resize(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }
    long long j = modInvFE(n, mod), ans = 0LL;
    for (int i = 1; i <= n; i++) {
        dd.assign(n + 1, false);
        vector<int> a;
        ans = (ans + ((j * dfs(i, a)) % mod)) % mod;
        //cout << ans << endl;
    }
    cout << ans;

    return 0;
}
