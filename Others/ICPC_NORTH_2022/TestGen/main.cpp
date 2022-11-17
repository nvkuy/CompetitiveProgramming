#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void genPermutation(int n) {
    vector<int> perm;
    for (int i = 1; i <= n; i++)
        perm.push_back(i);
    random_shuffle(perm.begin(), perm.end());
    for (int i = 0; i < n; i++)
        cout << perm[i] << ' ';
}

// genArr, element from lower->upper, order: 1(inc), -1(dec)
void genArr(long long n, long long lower, long long upper, int order) {
    vector<long long> arr;
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % (upper - lower + 1) + lower);
    if (order == 1)
        sort(arr.begin(), arr.end());
    if (order == -1)
        sort(arr.begin(), arr.end(), greater<long long>());
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

// genPairArr, element from lower->upper, order: 1(p.first >= p.second), -1(p.first < p.second)
void genPairArr(long long n, long long lower, long long upper, int order) {
    for (int i = 0; i < n; i++) {
        long long a = rand() % (upper - lower + 1) + lower;
        long long b = rand() % (upper - lower + 1) + lower;
        if (order == 1) {
            if (a < b)
                swap(a, b);
        }
        if (order == -1) {
            if (a > b)
                swap(a, b);
        }
        cout << a << ' ' << b << '\n';
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("test_gen.txt", "w", stdout);
    srand(time(NULL));
	int tn = 100, tq = tn, maxVal = 1e9;
	genPermutation(tn);
	cout << '\n';
	cout << tn << ' ' << tq << '\n';
    genArr(tn, 0, maxVal, -1);
    cout << '\n';
    genPairArr(tq, 0, maxVal, 1);


    return 0;

}
