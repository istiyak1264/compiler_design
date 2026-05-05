#include <stdio.h>

float f(float x, float y) { return x - y; }

int main() {
    float x0, y0, h, xn;
    int iters, n, i, j, k;
    printf("Enter x0, y0, h, xn, iterations: ");
    scanf("%f %f %f %f %d", &x0, &y0, &h, &xn, &iters);
    n = (xn - x0) / h;
    float y[iters+1][n+1];
    for (i = 0; i <= n; i++) y[0][i] = y0;
    for (j = 1; j <= iters; j++) {
        y[j][0] = y0;
        for (i = 1; i <= n; i++) {
            float integral = f(x0, y[j-1][0]);
            for (k = 1; k < i; k++) integral += 2 * f(x0 + k*h, y[j-1][k]);
            integral += f(x0 + i*h, y[j-1][i]);
            y[j][i] = y0 + integral * (h / 2.0);
        }
    }
    printf("\nx");
    for (j = 1; j <= iters; j++) printf("\t\ty%d", j);
    printf("\n");
    for (i = 0; i <= n; i++) {
        printf("%.4f", x0 + i*h);
        for (j = 1; j <= iters; j++) printf("\t\t%.6f", y[j][i]);
        printf("\n");
    }
}
