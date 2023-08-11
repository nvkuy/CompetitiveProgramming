#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool isGood(int l, int r, const vector<int> &a) {
    // multiset<int> s1, s2;
    // for (int i = l; i <= r; i++) s2.insert(a[i]);
    // for (int i = l; i <= r; i++) {
    //     s2.erase(s2.lower_bound(a[i]));
    //     auto it1 = s1.upper_bound(a[i]), it2 = s2.lower_bound(a[i]);
    //     bool has1 = false, has2 = false;
    //     if (s1.size() > 0 && it1 != s1.begin()) has1 = true;
    //     if (s2.size() > 0 && it2 != s2.end()) has2 = true;
    //     if (has1 && has2) return false;
    //     s1.insert(a[i]);
    // }
    // s2 = s1;
    // s1.clear();
    // for (int i = l; i <= r; i++) {
    //     s2.erase(s2.lower_bound(a[i]));
    //     auto it1 = s1.lower_bound(a[i]), it2 = s2.upper_bound(a[i]);
    //     bool has1 = false, has2 = false;
    //     if (s1.size() > 0 && it1 != s1.end()) has1 = true;
    //     if (s2.size() > 0 && it2 != s2.begin()) has2 = true;
    //     if (has1 && has2) return false;
    //     s1.insert(a[i]);
    // }
    // return true;
    for (int i = l; i <= r; i++) {
        bool greaterBefore = false, greaterAfter = false, lowerBefore = false, lowerAfter = false;
        for (int j = l; j < i; j++) {
            if (a[i] == a[j]) lowerBefore = greaterBefore = true;
            else if (a[i] > a[j]) lowerBefore = true;
            else greaterBefore = true;
        }
        for (int j = i + 1; j <= r; j++) {
            if (a[i] == a[j]) lowerAfter = greaterAfter = true;
            else if (a[i] > a[j]) lowerAfter = true;
            else greaterAfter = true;
        }
        if ((greaterBefore && lowerAfter) || (lowerBefore && greaterAfter))
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && isGood(i, j, a)) j++;
            // cout << "@i: " << i << ' ' << j << endl;
            ans += (j - i);
            assert(j - i < 5); //claim that good sub array size can't be too large!
        }
        cout << ans << endl;
    }

    return 0;
}
