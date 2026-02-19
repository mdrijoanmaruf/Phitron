#include <stdio.h>

int main() {
    float x1, y1, x2, y2, x3, y3;
    float area;

    printf("Enter coordinates of P (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter coordinates of Q (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    printf("Enter coordinates of R (x3 y3): ");
    scanf("%f %f", &x3, &y3);

    area = (x1*(y2 - y3) +
            x2*(y3 - y1) +
            x3*(y1 - y2)) / 2.0;

    if (area < 0) {
        area = -area;
    }

    printf("Area of the triangle = %.2f\n", area);

    return 0;
}