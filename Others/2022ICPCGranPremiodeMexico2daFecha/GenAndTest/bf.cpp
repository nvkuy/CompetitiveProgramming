#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool isOk(int num) {
    bitset<33> bs(num);
    string tmp = bs.to_string();
    reverse(tmp.begin(), tmp.end());
    while (tmp.back() == '0')
        tmp.pop_back();
    for (int i = 0; i < tmp.length() / 2; i++)
        if (tmp[i] != tmp[tmp.length() - i - 1])
            return false;
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int ans = 0;
        for (int i = l; i <= r; i++)
            ans += isOk(i);
        cout << ans << endl;
    }
    

    return 0;
}
