#include <bits/stdc++.h>
using namespace std;

vector<int> num, dd;
vector<vector<int>> sub_bit;
int c;

int bf(int ai) {
    for (int i = 0; i <= c; i++) {
        for (int j : sub_bit[i]) {
            bitset<18> bs(j);
            int bi = ai;
            for (int k = 0; k < c; k++)
                if (bs[k] == 0) bi ^= (1 << k);
            if (dd[bi])
                return c - bs.count();
        }
    }
    return 0;
}

int main()
{

    int n;
    cin >> c >> n;
    string s;
    dd.assign(1 << c, 0);
    for (int i = 0; i < n; i++) {
        cin >> s;
        int tmp = 0;
        for (int j = 0; j < c; j++)
            tmp ^= ((1 << j) * (s[j] == 'G'));
        num.push_back(tmp);
        dd[tmp] = 1;
    }
    sub_bit.resize(c + 1);
    for (int i = 0; i < (1 << c); i++) {
        sub_bit[__builtin_popcount(i)].push_back(i);
    }
    for (int i = 0; i < num.size(); i++)
        cout << bf(num[i]) << endl;

    return 0;
}
