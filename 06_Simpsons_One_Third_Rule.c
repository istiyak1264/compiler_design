#include <stdio.h>

double f(double x) { return 1.0 / (1.0 + x*x); }

int main() {
    double a, b, h, sum;
    int n, i;
    printf("Enter a, b, n (even): ");
    scanf("%lf %lf %d", &a, &b, &n);
    if (n % 2 != 0) { printf("n must be even.\n"); return 1; }
    h = (b - a) / n;
    sum = f(a) + f(b);
    for (i = 1; i < n; i++) sum += (i % 2 == 0 ? 2 : 4) * f(a + i*h);
    printf("Integral ≈ %.10f\n", (h/3) * sum);
}
