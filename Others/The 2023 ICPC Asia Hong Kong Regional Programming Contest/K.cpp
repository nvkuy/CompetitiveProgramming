#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define FOD(i, a, b) for (ll i = a; i > b; i--)
#define vi vector<ll>
#define vs vector<string>
#define vvi vector<vector<ll>>
#define vii vector<pair<ll, ll>>

bool multiTest = 0;

const ll maxN = ll(2e5 + 1);
const ll mod = ll(1e9 + 7);

void solved()
{
    ll n;
    cin >> n;

    vi a(n);
    ll g = 0;
    FOR(i, 0, n)
    {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    sort(all(a));
    ll ans = INT_MAX;

    FOR(i, 1, n)
    {
        if (a[i] % a[0] == 0)
            continue;
        ll x = (a[i] - 1) / 2;
        ans = min(ans, x);
        // cout << ans;
    }
    if (ans >= a[0])
        ans = a[0];
    else if (ans > (a[0] - 1) / 2)
        ans = (a[0] - 1) / 2;
    cout << max(ans, g);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);

    ll tc;
    if (multiTest)
        cin >> tc;
    else
        tc = 1;
    while (tc--)
    {
        solved();
        cout << endl;
    }

    return 0;
}