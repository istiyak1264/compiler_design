#include <stdio.h>

int main() {
    float x[20], y[20][20], val, h, u, sum, term = 1;
    int n, i, j;
    printf("Enter n: "); scanf("%d", &n);
    for (i = 0; i < n; i++) { printf("x[%d] y[%d]: ", i, i); scanf("%f %f", &x[i], &y[i][0]); }
    for (j = 1; j < n; j++)
        for (i = n-1; i >= j; i--)
            y[i][j] = y[i][j-1] - y[i-1][j-1];
    printf("Interpolate at x: "); scanf("%f", &val);
    h = x[1] - x[0];
    u = (val - x[n-1]) / h;
    sum = y[n-1][0];
    for (i = 1; i < n; i++) {
        term *= (u + i - 1) / i;
        sum += term * y[n-1][i];
    }
    printf("y(%.2f) ≈ %.4f\n", val, sum);
}
