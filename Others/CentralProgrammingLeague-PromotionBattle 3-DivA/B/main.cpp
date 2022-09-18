#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct line {
    long long a, b, c;
    line(long long aa, long long bb, long long cc) {
        a = aa, b = bb, c = cc;
    }
};

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool lineCmp(line l1, line l2) {
    if (l1.a == l2.a) {
        if (l1.b == l2.b) {
            return l1.c < l2.c;
        }
        return l1.b < l2.b;
    }
    return l1.a < l2.a;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, a, b, c, real_lines = 0;
    vector<line> lines;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        long long tmp = gcd(abs(a), abs(b));
        tmp = gcd(tmp, abs(c));
        a /= tmp, b /= tmp, c /= tmp;
        if ((a < 0) || (a == 0 && b < 0))
            a = -a, b = -b, c = -c;
        lines.push_back(line(a, b, c));
    }
    sort(lines.begin(), lines.end(), lineCmp);
    vector<long long> cnt;
    line preLine = line(0, 0, 0);
    for (int i = 0; i < n; i++) {
        real_lines++;
        if (lines[i].a != preLine.a) {
            cnt.push_back(1);
            preLine = lines[i];
            continue;
        }
        if (lines[i].b != preLine.b) {
            cnt.push_back(1);
            preLine = lines[i];
            continue;
        }
        if (lines[i].c != preLine.c) {
            cnt.back()++;
            preLine = lines[i];
            continue;
        }
        real_lines--;
        //cnt.back()++;
        //preLine = lines[i];
    }
    long long ans = 0, mod = 1e9 + 7;
    ans = ((real_lines - 2LL) * (real_lines - 1LL) * real_lines) / 6LL;
    for (int i = 0; i < cnt.size(); i++) {
        long long other_lines = real_lines - cnt[i];
        ans -= ((cnt[i] * (cnt[i] - 1LL) * (cnt[i] - 2LL)) / 6LL);
        ans -= ((cnt[i] * (cnt[i] - 1LL) * other_lines) / 2LL);
    }
    cout << (ans % mod);

    return 0;
}
