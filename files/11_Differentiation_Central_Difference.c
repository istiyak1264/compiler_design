#include <stdio.h>
#include <math.h>

double f(double x) { return x*x*x - x - 2; }

int main() {
    double x, h;
    int ch;
    printf("Enter x, h: "); scanf("%lf %lf", &x, &h);
    printf("1.First  2.Second  3.Third derivative: "); scanf("%d", &ch);
    if      (ch == 1) printf("f'(x)   ≈ %.8f\n", (f(x+h) - f(x-h)) / (2*h));
    else if (ch == 2) printf("f''(x)  ≈ %.8f\n", (f(x+h) - 2*f(x) + f(x-h)) / (h*h));
    else if (ch == 3) printf("f'''(x) ≈ %.8f\n", (f(x+2*h) - 2*f(x+h) + 2*f(x-h) - f(x-2*h)) / (2*h*h*h));
    else printf("Invalid choice.\n");
}
