#include <stdio.h>
#include <math.h>

double f(double x) { return x*x*x - x - 2; }

int main() {
    double x0, x1, x2, tol;
    int iter = 0, max;
    printf("Enter x0, x1, tolerance, max_iter: ");
    scanf("%lf %lf %lf %d", &x0, &x1, &tol, &max);
    printf("\nIter\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do {
        if (f(x1) - f(x0) == 0) { printf("Division by zero.\n"); return 1; }
        x2 = x1 - f(x1)*(x1-x0)/(f(x1)-f(x0));
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\n", ++iter, x0, x1, x2, f(x2));
        x0 = x1; x1 = x2;
    } while (fabs(f(x2)) > tol && iter < max);
    printf("Root ≈ %.6f\n", x2);
}
