#include <stdio.h>
#include <math.h>

double f(double x)  { return x*x*x - x - 2; }
double df(double x) { return 3*x*x - 1; }

int main() {
    double x0, x1, tol;
    int iter = 1, max;
    printf("Enter x0, tolerance, max_iter: ");
    scanf("%lf %lf %d", &x0, &tol, &max);
    printf("\nIter\t\tx0\t\tf(x0)\t\tx1\n");
    while (iter <= max) {
        if (df(x0) == 0) { printf("Derivative zero.\n"); return 1; }
        x1 = x0 - f(x0)/df(x0);
        printf("%d\t\t%.6f\t%.6f\t%.6f\n", iter, x0, f(x0), x1);
        if (fabs(x1 - x0) < tol) { printf("Root ≈ %.6f\n", x1); return 0; }
        x0 = x1; iter++;
    }
    printf("Did not converge.\n");
}
