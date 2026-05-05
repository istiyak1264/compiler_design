#include <stdio.h>

float f(float x, float y) { return x + y; }

int main() {
    float x, y, h, xn, k1, k2, k3, k4;
    printf("Enter x0, y0, h, xn: "); scanf("%f %f %f %f", &x, &y, &h, &xn);
    printf("\nx\t\ty\n%.4f\t\t%.6f\n", x, y);
    while (x < xn - 1e-6) {
        k1 = h * f(x, y);
        k2 = h * f(x + h/2, y + k1/2);
        k3 = h * f(x + h/2, y + k2/2);
        k4 = h * f(x + h,   y + k3);
        y += (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x += h;
        printf("%.4f\t\t%.6f\n", x, y);
    }
}
