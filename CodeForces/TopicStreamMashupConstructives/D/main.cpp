#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, k, s;
    cin >> n >> k >> s;
    if ((n - 1) * k < s || k > s) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    long long nBigMove = s % k, nSmallMove = k - nBigMove, smallMove = s / k, bigMove = smallMove + 1;
    long long curPos = 1;
    while (nBigMove--) {
        if (curPos + bigMove <= n)
            curPos += bigMove;
        else
            curPos -= bigMove;
        cout << curPos << ' ';
    }
    while (nSmallMove--) {
        if (curPos + smallMove <= n)
            curPos += smallMove;
        else
            curPos -= smallMove;
        cout << curPos << ' ';
    }

    return 0;
}
