#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, iter, max;
    float tol, err, omega;
    printf("Enter n: "); scanf("%d", &n);
    float a[n][n+1], x[n];
    printf("Enter augmented matrix [A|b] row by row:\n");
    for (i = 0; i < n; i++) { for (j = 0; j <= n; j++) scanf("%f", &a[i][j]); x[i] = 0; }
    printf("Enter omega (relaxation factor, 0<w<2), tolerance, max_iter: ");
    scanf("%f %f %d", &omega, &tol, &max);

    printf("\nIter");
    for (i = 0; i < n; i++) printf("\t\tx[%d]", i+1);
    printf("\n");

    for (iter = 1; iter <= max; iter++) {
        err = 0;
        for (i = 0; i < n; i++) {
            float gs = a[i][n];
            for (j = 0; j < n; j++) if (j != i) gs -= a[i][j] * x[j];
            gs /= a[i][i];
            float xnew = (1 - omega) * x[i] + omega * gs;   // SOR update
            if (fabs(xnew - x[i]) > err) err = fabs(xnew - x[i]);
            x[i] = xnew;
        }
        printf("%d", iter);
        for (i = 0; i < n; i++) printf("\t\t%.6f", x[i]);
        printf("\n");
        if (err < tol) break;
    }
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) printf("x[%d] = %.6f\n", i+1, x[i]);
}
