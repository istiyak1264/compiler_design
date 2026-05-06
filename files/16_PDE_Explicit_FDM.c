#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int nx, nt, i, j;
    float L, Tmax, alpha, dx, dt, r;

    printf("Enter L, Tmax, nx, nt, alpha: ");
    scanf("%f %f %d %d %f", &L, &Tmax, &nx, &nt, &alpha);

    dx = L / nx;
    dt = Tmax / nt;
    r = alpha * alpha * dt / (dx * dx);

    float **u = (float**)malloc((nt + 1) * sizeof(float*));
    for (i = 0; i <= nt; i++)
        u[i] = (float*)calloc(nx + 1, sizeof(float));

    for (i = 0; i <= nx; i++)
        u[0][i] = sin(PI * i * dx / L);

    for (j = 0; j < nt; j++) {
        u[j][0] = 0;
        u[j][nx] = 0;

        for (i = 1; i < nx; i++)
            u[j + 1][i] = u[j][i] + r * (u[j][i + 1] - 2 * u[j][i] + u[j][i - 1]);
    }

    printf("\nx\t\tu(x, %.2f)\n", Tmax);

    for (i = 0; i <= nx; i += (nx/10 > 0 ? nx/10 : 1))
        printf("%.4f\t\t%.8f\n", i * dx, u[nt][i]);

    printf("Stability r = %.4f %s\n", r, r > 0.5 ? "→ UNSTABLE!" : "→ Stable");

    for (i = 0; i <= nt; i++)
        free(u[i]);
    free(u);

    return 0;
}