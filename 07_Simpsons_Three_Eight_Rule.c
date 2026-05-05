#include <stdio.h>

double f(double x) { return 1.0 / (1.0 + x*x); }

int main() {
    double a, b, h, sum;
    int n, i;
    printf("Enter a, b, n (multiple of 3): ");
    scanf("%lf %lf %d", &a, &b, &n);
    if (n % 3 != 0) { printf("n must be multiple of 3.\n"); return 1; }
    h = (b - a) / n;
    sum = f(a) + f(b);
    for (i = 1; i < n; i++) sum += (i % 3 == 0 ? 2 : 3) * f(a + i*h);
    printf("Integral ≈ %.10f\n", (3*h/8) * sum);
}
