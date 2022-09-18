#include <stdio.h>
#include <conio.h>
/*
// 1+2+..n
unsigned long cal (int n) {
    if (n == 1)
        return 1;
    else
        return n + cal(n - 1);
}
*/
/*
// fib(n)
unsigned long cal (int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return cal(n - 1) + cal(n - 2);
}
*/
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    /*
    int n;
    scanf("%d", &n);
    printf("%ld", cal(n));
    */
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));

    return 0;
}
