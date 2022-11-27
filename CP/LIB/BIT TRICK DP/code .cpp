#include <bits/stdc++.h>
using namespace std;

int main() {

    int const N = 16;
    long long F[1 << N], A[1 << N];
    // SOS DP: Given array size 2^n, for mask x => f[mask] = sum all a[i] if (i & mask) == i, complexity: N*2^N
    for(int i = 0; i<(1<<N); ++i)
        F[i] = A[i];
    for(int i = 0;i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask){
        if(mask & (1<<i))
            F[mask] += F[mask^(1<<i)];
    }

    // Gen all sub mask s of mask m, complexity: 3^N
    for (int m=0; m<(1<<N); ++m) {
        for (int s=m; s; s=(s-1)&m) {
            //... s and m ...
        }
    }

    // Gen all sub set K element
    int k = 16;
    int s = (1 << k) - 1;
    while (!(s & 1 << N)) 
    {
        //s..
        int lo = s & ~(s - 1);  
        int lz = (s + lo) & ~s;  
        s |= lz;                       
        s &= ~(lz - 1);        
        s |= (lz / lo / 2) - 1;   
    }

    return 0;
}