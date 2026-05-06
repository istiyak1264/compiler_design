#include <stdio.h>

int main() {
    float x[20], y[20], d[20][20], xp, h, u, dy, d2y, d3y;
    int n, i, j;
    printf("Enter n: "); scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%f", &x[i]);
    for (i = 0; i < n; i++) scanf("%f", &y[i]);
    printf("Find derivative at x: "); scanf("%f", &xp);
    h = x[1] - x[0];
    u = (xp - x[0]) / h;
    for (i = 0; i < n; i++) d[i][0] = y[i];
    for (j = 1; j < n; j++)
        for (i = 0; i < n-j; i++)
            d[i][j] = d[i+1][j-1] - d[i][j-1];
    dy  = (d[0][1] + (2*u-1)/2.0*d[0][2] + (3*u*u-6*u+2)/6.0*d[0][3]) / h;
    d2y = (d[0][2] + (u-1)*d[0][3]) / (h*h);
    d3y = d[0][3] / (h*h*h);
    printf("f'(x)   = %.6f\nf''(x)  = %.6f\nf'''(x) = %.6f\n", dy, d2y, d3y);
}
