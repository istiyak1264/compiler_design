#include <stdio.h>

float f(float x, float y) { return x - y; }

int main() {
    float x, y, h, xn;
    printf("Enter x0, y0, h, xn: "); scanf("%f %f %f %f", &x, &y, &h, &xn);
    printf("\nx\t\ty\n%.4f\t\t%.6f\n", x, y);
    while (x < xn - 1e-6) {
        y += h * f(x, y);
        x += h;
        printf("%.4f\t\t%.6f\n", x, y);
    }
}
