#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct juice {
    int cost;
    bool hasA, hasB, hasC;
    juice(int ci) {
        cost = ci;
        hasA = hasB = hasC = false;
    }
    void setA() {
        hasA = true;
    }
    void setB() {
        hasB = true;
    }
    void setC() {
        hasC = true;
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, minA = 1e9, minB = 1e9, minC = 1e9, ans = 1e9, ci;
    string s;
    vector<juice> arr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ci;
        cin.ignore();
        getline(cin, s);
        arr.push_back(juice(ci));
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'A') {
                arr.back().setA();
                minA = min(minA, ci);
            }
            if (s[j] == 'B'){
                arr.back().setB();
                minB = min(minB, ci);
            }
            if (s[j] == 'C'){
                arr.back().setC();
                minC = min(minC, ci);
            }
        }
    }
    ans = min(ans, minA + minB + minC);
    for (int i = 0; i < n; i++) {
        if (arr[i].hasA && arr[i].hasB && arr[i].hasC)
            ans = min(ans, arr[i].cost);
        if (arr[i].hasA && arr[i].hasB)
            ans = min(ans, arr[i].cost + minC);
        if (arr[i].hasA && arr[i].hasC)
            ans = min(ans, arr[i].cost + minB);
        if (arr[i].hasB && arr[i].hasC)
            ans = min(ans, arr[i].cost + minA);
        if (arr[i].hasA)
            ans = min(ans, arr[i].cost + minB + minC);
        if (arr[i].hasB)
            ans = min(ans, arr[i].cost + minA + minC);
        if (arr[i].hasC)
            ans = min(ans, arr[i].cost + minB + minA);
    }
    if (ans >= 1e9)
        ans = -1;
    cout << ans;

    return 0;
}
