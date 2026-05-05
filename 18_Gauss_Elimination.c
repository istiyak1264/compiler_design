#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    printf("Enter n: "); scanf("%d", &n);
    float a[n][n+1], x[n];
    printf("Enter augmented matrix [A|b] row by row:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            scanf("%f", &a[i][j]);

    // Forward elimination
    for (k = 0; k < n; k++) {
        // Partial pivoting
        for (i = k+1; i < n; i++)
            if (fabs(a[i][k]) > fabs(a[k][k]))
                for (j = 0; j <= n; j++) { float t = a[k][j]; a[k][j] = a[i][j]; a[i][j] = t; }
        if (a[k][k] == 0) { printf("No unique solution.\n"); return 1; }
        for (i = k+1; i < n; i++) {
            float factor = a[i][k] / a[k][k];
            for (j = k; j <= n; j++) a[i][j] -= factor * a[k][j];
        }
    }

    // Back substitution
    for (i = n-1; i >= 0; i--) {
        x[i] = a[i][n];
        for (j = i+1; j < n; j++) x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++) printf("x[%d] = %.6f\n", i+1, x[i]);
}
