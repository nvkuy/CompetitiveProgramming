#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void sieve(int n, vector<int> &isPrime) {
    isPrime.assign(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= n; ++i) {
         if(isPrime[i] == true) {
             for(int j = i * i; j <= n; j += i)
                 isPrime[j] = false;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> isPrime;
    sieve(2e5 + 5, isPrime);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> primes, normal;
        for (int i = 1; i <= n; i++) {
            if (isPrime[i])
                primes.push_back(i);
            else
                normal.push_back(i);
        }
        vector<int> all_num;
        for (int num : normal)
            all_num.push_back(num);
        for (int num : primes)
            all_num.push_back(num);
        reverse(all_num.begin(), all_num.end());
        deque<int> ans;
        while (true) {
            if (all_num.size() == 0) break;
            ans.push_back(all_num.back());
            all_num.pop_back();
            if (all_num.size() == 0) break;
            ans.push_front(all_num.back());
            all_num.pop_back();
        }
        for (int num : ans)
            cout << num << ' ';
        cout << endl;
    }

    return 0;
}
