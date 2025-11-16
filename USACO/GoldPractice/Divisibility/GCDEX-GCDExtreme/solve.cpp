#include <bits/stdc++.h>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAX_N = 1e6 + 5;
long long phi[MAX_N], fn[MAX_N];

void pre_phi() {
    vector<int> primes;
	for (int i = 1; i < MAX_N; i++) { phi[i] = i; }
	for (int i = 2; i < MAX_N; i++) {
		if (phi[i] == i) {
			primes.push_back(i);
            phi[i] = i - 1;
		}
        for (int j = 0; j < primes.size () && i * primes[j] < MAX_N; j++) {
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = primes[j] * phi[i];
                break;
            }
            phi[i * primes[j]] = (primes[j] - 1) * phi[i];
        }
	}
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    pre_phi();

    memset(fn, 0, MAX_N * sizeof(long long));
    for (long long i = 1; i < MAX_N; i++) {
        for (long long j = i; i * j < MAX_N; j++) {
            fn[i * j] += i * phi[j];
            if (i != j) fn[i * j] += j * phi[i];
        }
        fn[i] += fn[i - 1] - i;
    }

    int n;
    while (true) {

        cin >> n;
        if (n == 0) break;

        cout << fn[n] << endl;

    }


    return 0;
}
