#include <stdio.h>

int main() {

    int n, a[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < (n - 1); i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                a[i] ^= a[j];
                a[j] ^= a[i];
                a[i] ^= a[j];
            }
        }
    }
    //for (int i = 0; i < n; i++)
    //    printf("%d ", a[i]);
    //printf("\n");

    for (int i = (n - 1); i >= 2; i--) {
        for (int j = i - 1; j >= 1; j--) {
            for (int k = j - 1; k >= 0; k--) {
                if (a[i] < (a[j] + a[k])) {
                    printf("%d", (a[i] + a[j] + a[k]));
                    return 0;
                }

            }
        }
    }
    printf("0");

    return 0;
}
