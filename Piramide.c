#include <stdio.h>
#include <math.h>

void calcularDistancia(float coor1[3], float coor2[3], float *distancia);
void calcularPerimetro(float coor1[3], float coor2[3], float coor3[3], float coor4[3], float *perimetro);
void calcularArea(float coor1[3], float coor2[3], float coor3[3], float coor4[3], float *area);

int main() {
    float P1[] = {0, 0, 3};
    float P2[] = {3, 0, 0};
    float P3[] = {0, 0, 0};
    float P4[] = {1, 7, 1};

    float distancia, perimetro, area;

    calcularDistancia(P1, P2, &distancia);
    printf("Distancia de la figura: %.2f\n", distancia);

    calcularPerimetro(P1, P2, P3, P4, &perimetro);
    printf("Perimetro de la figura: %.2f\n", perimetro);

    calcularArea(P1, P2, P3, P4, &area);
    printf("Area de la figura: %.2f\n", area);

}

void calcularDistancia(float coor1[3], float coor2[3], float *distancia) {
    float dx = coor2[0] - coor1[0];
    float dy = coor2[1] - coor1[1];
    float dz = coor2[2] - coor1[2];

    *distancia = sqrt(dx * dx + dy * dy + dz * dz);
}

void calcularPerimetro(float coor1[3], float coor2[3], float coor3[3], float coor4[3], float *perimetro) {
    float distancia;
    calcularDistancia(coor1, coor2, &distancia);
    *perimetro = distancia;

    calcularDistancia(coor2, coor3, &distancia);
    *perimetro += distancia;

    calcularDistancia(coor3, coor4, &distancia);
    *perimetro += distancia;

    calcularDistancia(coor4, coor1, &distancia);
    *perimetro += distancia;
}

void calcularArea(float coor1[3], float coor2[3], float coor3[3], float coor4[3], float *area) {
    float base, altura;
    calcularDistancia(coor1, coor3, &base);
    calcularDistancia(coor2, coor3, &altura);

    *area = base * altura / 2;
}
