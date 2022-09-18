#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long mod = 1e9 + 7;
map<pair<long long, int>, long long> f;
vector<long long> numGen, a;

long long arrToNum(deque<int> &dq) {
    vector<int> bitNum(55, 0);
    for (int i = 0; i < dq.size(); i++)
        bitNum[dq[i]] = 1;
    long long num = 0;
    for (int i = 0; i < 55; i++) {
        if (bitNum[i])
            num += (1LL << i);
    }
    return num;
}

void genNum(deque<int> &dq) {
    numGen.clear();
    for (int len = 1; len <= dq.size(); len++) {
        deque<int> tmp;
        for (int i = 0; i < len; i++)
            tmp.push_back(dq[i]);
        numGen.push_back(arrToNum(tmp));
        for (int i = len; i < dq.size(); i++) {
            tmp.push_back(dq[i]);
            tmp.pop_front();
            numGen.push_back(arrToNum(tmp));
        }
    }
}

void dp(deque<int> &dq, int time, long long init_val) {
    genNum(dq);
    long long num = arrToNum(dq);
    f[make_pair(num, 0)] = init_val;
    for (int t = 1; t <= time; t++) {
        long long tmp = 0;
        for (int i = 0; i < numGen.size(); i++)
            tmp = (tmp + f[make_pair(numGen[i], t - 1)]) % mod;
        f[make_pair(num, t)] = tmp;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt, n, t;
    cin >> tt;
    while (tt--) {
        f.clear();
        cin >> n >> t;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int len = 1; len <= a.size(); len++) {
            deque<int> tmp;
            long long init_sum = 0;
            for (int i = 0; i < len; i++) {
                tmp.push_back(i);
                init_sum += a[i];
            }
            dp(tmp, t, init_sum);
            for (int i = len; i < a.size(); i++) {
                init_sum += a[i]; init_sum -= a[i - len];
                tmp.push_back(i);
                tmp.pop_front();
                dp(tmp, t, init_sum);
            }
        }
        deque<int> arr;
        for (int i = 0; i < n; i++)
            arr.push_back(i);
        //cout << "ANS: ";
        cout << f[make_pair(arrToNum(arr), t)] << endl;
    }

    return 0;
}
