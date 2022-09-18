#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n1, n2;
vector<int> a1, a2;

void addBitChar(char c, vector<int> &arr) {
    int num;
    if (c >= '0' && c <= '9')
        num = c - '0';
    else
        num = c - 'A' + 10;
    bitset<4> bs(num);
    arr.push_back(bs[0]), arr.push_back(bs[1]);
    arr.push_back(bs[2]), arr.push_back(bs[3]);
}

bool check(int i) {
    if (i + n1 > n2)
        return false;
    for (int j = 0; j < n1; j++) {
        if (a2[i + j] != a1[j])
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    //cout << s1 << endl << s2 << endl;
    for (int i = 0; i < s1.length(); i++)
        addBitChar(s1[i], a1);
    for (int i = 0; i < s2.length(); i++)
        addBitChar(s2[i], a2);
    n1 = a1.size(), n2 = a2.size();
    int ans = 0;
    for (int i = 0; i < n2; i++)
        ans += check(i);
    cout << ans;

    return 0;
}
