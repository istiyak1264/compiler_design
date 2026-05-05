#include <stdio.h>

double f(double x) { return 1.0 / (1.0 + x*x); }

int main() {
    double a, b, h, sum;
    int n, i;
    printf("Enter a, b, n: ");
    scanf("%lf %lf %d", &a, &b, &n);
    h = (b - a) / n;
    sum = f(a) + f(b);
    for (i = 1; i < n; i++) sum += 2 * f(a + i*h);
    printf("Integral ≈ %.10f\n", (h/2) * sum);
}
