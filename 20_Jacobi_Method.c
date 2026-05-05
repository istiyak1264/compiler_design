#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, iter, max;
    float tol, err;
    printf("Enter n: "); scanf("%d", &n);
    float a[n][n+1], x[n], xn[n];
    printf("Enter augmented matrix [A|b] row by row:\n");
    for (i = 0; i < n; i++) { for (j = 0; j <= n; j++) scanf("%f", &a[i][j]); x[i] = 0; }
    printf("Enter tolerance, max_iter: "); scanf("%f %d", &tol, &max);

    printf("\nIter");
    for (i = 0; i < n; i++) printf("\t\tx[%d]", i+1);
    printf("\n");

    for (iter = 1; iter <= max; iter++) {
        err = 0;
        for (i = 0; i < n; i++) {
            xn[i] = a[i][n];
            for (j = 0; j < n; j++) if (j != i) xn[i] -= a[i][j] * x[j];
            xn[i] /= a[i][i];           // use old x[] values only (Jacobi)
            if (fabs(xn[i] - x[i]) > err) err = fabs(xn[i] - x[i]);
        }
        for (i = 0; i < n; i++) x[i] = xn[i];
        printf("%d", iter);
        for (i = 0; i < n; i++) printf("\t\t%.6f", x[i]);
        printf("\n");
        if (err < tol) break;
    }
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) printf("x[%d] = %.6f\n", i+1, x[i]);
}
