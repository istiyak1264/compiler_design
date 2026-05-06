#include <stdio.h>

int main()
{
    float x[20], y[20], val, sum = 0, term;
    int n, i, j;
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("x[%d] y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }
    printf("Interpolate at x: ");
    scanf("%f", &val);
    for (i = 0; i < n; i++)
    {
        term = y[i];
        for (j = 0; j < n; j++)
            if (j != i)
                term *= (val - x[j]) / (x[i] - x[j]);
        sum += term;
    }
    printf("y(%.2f) ≈ %.4f\n", val, sum);
}
