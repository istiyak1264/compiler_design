#include <stdio.h>
// 2x₁ + x₂ − x₃ = 8
// −3x₁ − x₂ + 2x₃ = −11
// −2x₁ + x₂ + 2x₃ = −3

int main()
{
    int n, i, j, k;
    printf("Enter n: ");
    scanf("%d", &n);
    float a[n][n + 1], L[n][n], U[n][n], x[n], y[n];

    printf("Enter augmented matrix [A|b] row by row:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
            scanf("%f", &a[i][j]);
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            L[i][j] = (i == j);
            U[i][j] = 0;
        }

    for (k = 0; k < n; k++)
    {
        for (j = k; j < n; j++)
        {
            U[k][j] = a[k][j];
            for (i = 0; i < k; i++)
                U[k][j] -= L[k][i] * U[i][j];
        }
        for (i = k + 1; i < n; i++)
        {
            L[i][k] = a[i][k];
            for (j = 0; j < k; j++)
                L[i][k] -= L[i][j] * U[j][k];
            L[i][k] /= U[k][k];
        }
    }

    for (i = 0; i < n; i++)
    {
        y[i] = a[i][n];
        for (j = 0; j < i; j++)
            y[i] -= L[i][j] * y[j];
    }
    for (i = n - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (j = i + 1; j < n; j++)
            x[i] -= U[i][j] * x[j];
        x[i] /= U[i][i];
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("x[%d] = %.6f\n", i + 1, x[i]);
}