 #include <stdio.h>
#include <math.h>

double f(double x) { return x*x*x - x - 2; }

int main() {
    double a, b, c, tol;
    int iter = 0, max;
    printf("Enter a, b, tolerance, max_iter: ");
    scanf("%lf %lf %lf %d", &a, &b, &tol, &max);
    if (f(a)*f(b) >= 0) { printf("Invalid interval.\n"); return 1; }
    printf("\nIter\t\ta\t\tb\t\tc\t\tf(c)\n");
    do {
        c = (a*f(b) - b*f(a)) / (f(b) - f(a));
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", ++iter, a, b, c, f(c));
        if (fabs(f(c)) < tol) break;
        (f(a)*f(c) < 0) ? (b = c) : (a = c);
    } while (iter < max);
    printf("Root ≈ %.6f\n", c);
}
