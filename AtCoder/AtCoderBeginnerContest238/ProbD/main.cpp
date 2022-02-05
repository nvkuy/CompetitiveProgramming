#include <bits/stdc++.h>

using namespace std;

long long n;
bool check(bitset<60> a, bitset<60> s, bool rm, long long i) {
    if ((1LL << i) > n)
        return (!rm);
    bool iok = false;
    if (a[i]) {
        if (s[i]) {
            if (!rm)
                return false;
            else
                iok = check(a, s, true, i + 1);
        } else {
            if (rm)
                return false;
            else
                iok = check(a, s, true, i + 1);
        }
    } else {
        if (s[i])
            iok = check(a, s, false, i + 1);
        else {
            if (rm)
                iok = check(a, s, true, i + 1);
            else
                iok = check(a, s, false, i + 1);
        }
    }
    //cout << "TEST: " << i << ' ' << iok << endl;
    return iok;
}

int main()
{
    int t;
    long long a, s;
    cin >> t;
    while (t--) {
        cin >> a >> s;
        bool ans = (s >= a);
        n = s;
        bitset<60> bs1(a), bs2(s);
        ans &= check(bs1, bs2, false, 0);
        cout << (ans ? "Yes" : "No") << endl;
    }

    return 0;
}
