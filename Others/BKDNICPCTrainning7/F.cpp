#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long _mergeSort(vector<int> &arr, int temp[], int left, int right);
long long merge(vector<int> &arr, int temp[], int left, int mid,
          int right);
  
/* This function sorts the
   input array and returns the
number of inversions in the array */
long long mergeSort(vector<int> &arr, int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}
  
/* An auxiliary recursive function
  that sorts the input array and
returns the number of inversions in the array. */
long long _mergeSort(vector<int> &arr, int temp[], int left, int right)
{
    long long mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2;
  
        /* Inversion count will be sum of
        inversions in left-part, right-part
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
  
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
  
/* This function merges two sorted arrays
and returns inversion count in the arrays.*/
long long merge(vector<int> &arr, int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    long long inv_count = 0;
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
  
            /* this is tricky -- see above
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }
  
    /* Copy the remaining elements of left subarray
(if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
  
    /* Copy the remaining elements of right subarray
       (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
  
    return inv_count;
}


long long cal(vector<int> a) {
    return mergeSort(a, a.size());
}


map<int, int> hf;
void compress(vector<int> a) {
    int num = 1;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (hf.find(a[i]) == hf.end()) {
            hf[a[i]] = num;
            num++;
        }
    }
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("in", "r", stdin);

    int n, m, l;
    cin >> n >> m;
    vector<vector<int>> w(m);
    vector<int> c(n), all_num;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        all_num.push_back(c[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> l;
        w[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> w[i][j];
            all_num.push_back(w[i][j]);
        }
    }

    compress(all_num);
    vector<long long> f(hf.size() + 1, 0);
    for (int i = 0; i < n; i++)
        f[hf[c[i]]]++;
    for (int i = 1; i < f.size(); i++)
        f[i] += f[i - 1];
    

    long long t1 = cal(c);

    for (int i = 0; i < m; i++) {
        long long ans = 1e16, tans = cal(w[i]) + t1;

        for (int j = 0; j < w[i].size(); j++)
            tans += (n - f[ hf[w[i][j]] ]);

        // cout << "@"  << tans << endl;       
        ans = min(ans, tans);
        for (int j = 0; j < w[i].size(); j++) {
            tans -= (n - f[ hf[w[i][j]] ]);
            tans += f[hf[w[i][j]] - 1];
            ans = min(ans, tans);

            // cout << "@"  << tans << endl;
        }
        cout << ans << endl;
    }

    return 0;
}