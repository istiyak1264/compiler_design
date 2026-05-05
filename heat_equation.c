/*
 * Heat Equation: du/dt = alpha * d2u/dx2
 * Method: Explicit Finite Difference (Forward Time, Central Space)
 *
 * Stability condition: r = alpha*dt/dx^2 <= 0.5
 *
 * Boundary conditions: u(0,t) = 0, u(L,t) = 0
 * Initial condition:   u(x,0) = sin(pi*x/L)
 */

#include <stdio.h>
#include <math.h>

#define N    10       /* number of spatial intervals */
#define L    1.0      /* rod length */
#define T    0.1      /* total time */
#define ALPHA 1.0     /* thermal diffusivity */

int main() {
    double dx = L / N;
    double dt = 0.4 * dx * dx / ALPHA;  /* chosen so r <= 0.5 (stable) */
    double r  = ALPHA * dt / (dx * dx); /* stability ratio */
    int    steps = (int)(T / dt);

    double u[N+1], u_new[N+1];
    int i, k;

    printf("Heat Equation — Explicit FDM\n");
    printf("dx=%.4f  dt=%.6f  r=%.4f  steps=%d\n\n", dx, dt, r, steps);

    /* --- Initial condition: u(x,0) = sin(pi*x/L) --- */
    for (i = 0; i <= N; i++)
        u[i] = sin(M_PI * i * dx / L);

    /* --- Time stepping --- */
    for (k = 0; k < steps; k++) {

        /* Boundary conditions */
        u_new[0] = 0.0;
        u_new[N] = 0.0;

        /* Interior nodes */
        for (i = 1; i < N; i++)
            u_new[i] = u[i] + r * (u[i+1] - 2*u[i] + u[i-1]);

        /* Update */
        for (i = 0; i <= N; i++)
            u[i] = u_new[i];
    }

    /* --- Print final solution vs exact solution --- */
    double t_final = steps * dt;
    printf("x\t\tNumerical\tExact\t\tError\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i <= N; i++) {
        double x     = i * dx;
        double exact = sin(M_PI * x / L) * exp(-ALPHA * M_PI*M_PI * t_final / (L*L));
        printf("%.4f\t\t%.6f\t%.6f\t%.2e\n", x, u[i], exact, fabs(u[i]-exact));
    }

    return 0;
}
