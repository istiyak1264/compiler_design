/*
 * Wave Equation: d2u/dt2 = c^2 * d2u/dx2
 * Method: Explicit Finite Difference (Central differences in both time & space)
 *
 * Stability condition (CFL): r = c*dt/dx <= 1.0
 *
 * Boundary conditions: u(0,t) = 0, u(L,t) = 0
 * Initial conditions:  u(x,0) = sin(pi*x/L),  du/dt(x,0) = 0
 */

#include <stdio.h>
#include <math.h>

#define N   10       /* number of spatial intervals */
#define L   1.0      /* string length */
#define T   1.0      /* total time */
#define C   1.0      /* wave speed */

int main() {
    double dx = L / N;
    double dt = 0.9 * dx / C;     /* CFL number = 0.9 (stable, < 1) */
    double r  = C * dt / dx;      /* CFL ratio */
    double r2 = r * r;
    int    steps = (int)(T / dt);

    double u_prev[N+1], u_curr[N+1], u_next[N+1];
    int i, k;

    printf("Wave Equation — Explicit FDM\n");
    printf("dx=%.4f  dt=%.6f  CFL=%.4f  steps=%d\n\n", dx, dt, r, steps);

    /* --- Initial condition: u(x,0) = sin(pi*x/L) --- */
    for (i = 0; i <= N; i++)
        u_curr[i] = sin(M_PI * i * dx / L);

    /* --- First time step using du/dt(x,0) = 0
           u_prev[i] = u_curr[i] - dt*0 = u_curr[i]           --- */
    for (i = 0; i <= N; i++)
        u_prev[i] = u_curr[i];

    /* --- Time stepping --- */
    for (k = 0; k < steps; k++) {

        /* Boundary conditions */
        u_next[0] = 0.0;
        u_next[N] = 0.0;

        /* Interior nodes */
        for (i = 1; i < N; i++)
            u_next[i] = 2*u_curr[i] - u_prev[i]
                        + r2 * (u_curr[i+1] - 2*u_curr[i] + u_curr[i-1]);

        /* Shift time levels */
        for (i = 0; i <= N; i++) {
            u_prev[i] = u_curr[i];
            u_curr[i] = u_next[i];
        }
    }

    /* --- Print final solution vs exact solution --- */
    double t_final = steps * dt;
    printf("x\t\tNumerical\tExact\t\tError\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i <= N; i++) {
        double x     = i * dx;
        double exact = sin(M_PI * x / L) * cos(M_PI * C * t_final / L);
        printf("%.4f\t\t%.6f\t%.6f\t%.2e\n", x, u_curr[i], exact, fabs(u_curr[i]-exact));
    }

    return 0;
}
