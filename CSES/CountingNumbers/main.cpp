#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int maxDigit = 19;

long long goodNumberUpToNum(vector<int> &num, vector<vector<long long>> &f) {

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long a, b;
    cin >> a >> b;
    vector<int> num1, num2;
    while (num1.size() < maxDigit) {
        num1.push_back(a % 10);
        a /= 10;
    }
    while (num2.size() < maxDigit) {
        num2.push_back(b % 10);
        b /= 10;
    }
    vector<vector<long long>> f(maxDigit, vector<long long>(10));
    for (int i = 0; i < 10; i++)
        f[0][i] = 1;
    for (int i = 1; i < maxDigit; i++) {
        long long tmp = 0;
        for (int j = 0; j < 10; j++)
            tmp += f[i - 1][j];
        for (int j = 0; j < 10; j++)
            f[i][j] = tmp - f[i - 1][j];
    }


    return 0;
}
