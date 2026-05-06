#include <stdio.h>

int main() {
    int n, i;
    float x[20], y[20];
    float sx=0, sx2=0, sx3=0, sx4=0, sy=0, sxy=0, sx2y=0;
    printf("Enter n: "); scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
        sx += x[i]; sx2 += x[i]*x[i]; sx3 += x[i]*x[i]*x[i]; sx4 += x[i]*x[i]*x[i]*x[i];
        sy += y[i]; sxy += x[i]*y[i]; sx2y += x[i]*x[i]*y[i];
    }
    /* Normal equations: [n sx sx2; sx sx2 sx3; sx2 sx3 sx4] [a;b;c] = [sy;sxy;sx2y] */
    float a[3][4] = {
        {n,   sx,  sx2,  sy  },
        {sx,  sx2, sx3,  sxy },
        {sx2, sx3, sx4,  sx2y}
    };
    /* Gauss elimination */
    int j, k;
    for (k = 0; k < 3; k++)
        for (i = k+1; i < 3; i++) {
            float f = a[i][k] / a[k][k];
            for (j = k; j <= 3; j++) a[i][j] -= f * a[k][j];
        }
    float coef[3];
    for (i = 2; i >= 0; i--) {
        coef[i] = a[i][3];
        for (j = i+1; j < 3; j++) coef[i] -= a[i][j] * coef[j];
        coef[i] /= a[i][i];
    }
    printf("Best fit parabola: y = %.4f + %.4fx + %.4fx^2\n", coef[0], coef[1], coef[2]);
}