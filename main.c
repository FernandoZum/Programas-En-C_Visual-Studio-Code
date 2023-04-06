#include <stdio.h>

int main (int argc, char *argv[])  
{

    char nombre[50];
    char cedula[10];

    float precioA=150, precioB=55, precioC=180, precioD=70, precioE=120;
    float numA=0, numB=0, numC=0, numD=0, numE=0;
    float subtotalA=0, subtotalB=0, subtotalC=0, subtotalD=0, subtotalE=0;
    float subtotal=0, total=0;

    char opcion='f';
    
    printf("******Escoja un producto que desee facturar: ******\n");
    printf("a) Llantas                  (Precio: $150)\n");
    printf("b) Kit Pastillas de Frenos  (Precio: $55)\n");
    printf("c) Kit de Embrague          (Precio: $180)\n");
    printf("d) Faro                     (Precio: $70)\n");
    printf("e) Radiador                 (Precio: $120)\n");
    scanf("%c",&opcion);

    switch (opcion)
    {
    case 'a':
        printf("Ingrese el numero de Llantas: \n");
        scanf("%f", &numA);
        break;
    case 'b':
        printf("Ingrese el numero de Kit de Pastillas de Freno: \n");
        scanf("%f", &numB);
        break;
    case 'c':
        printf("Ingrese el numero de Kit de Embrague: \n");
        scanf("%f", &numC);
        break;
    case 'd':
        printf("Ingrese el numero de Faros: \n");
        scanf("%f", &numD);
        break;
    case 'e':
        printf("Ingrese el numero de Radiadores: \n");
        scanf("%f", &numE);
        break;                    

    default:
        break;    
    }

    subtotalA=precioA*numA;
    subtotalB=precioB*numB;
    subtotalC=precioC*numC;
    subtotalD=precioD*numD;
    subtotalE=precioE*numE;

    subtotal=subtotalA+subtotalB+subtotalC+subtotalD+subtotalE;

    if (subtotal>100 && subtotal<=500)
    {
        total=subtotal-subtotal*0.05;
    }
    else if (subtotal>500 && subtotal<=1000)
    {
        total=subtotal-subtotal*0.07;
    }
    else if (subtotal>1000)
    {
        total=subtotal-subtotal*0.1;
    }
    
    printf("Ingrese el Nombre del Cliente: \n");
    scanf("%s", &nombre);
    printf("Ingrese la cedula del Cliente: \n");
    scanf("%s", &cedula);

    printf("******Datos del Cliente******");
    printf("Nmbre: %s\n", nombre);
    printf("Cedula: %s\n", cedula);
    printf("******Factura******");
    printf("        Producto            Cantidad            Precio Unitario             Precio Total");
    if (numA !=0)
    {
        printf("    Llantas                 %.0f                      %.2f                      %.2f",numA,precioA,subtotalA);
    }
    if (numB !=0)
    {
        printf("  Kit Frenos                %.0f                      %.2f                      %.2f",numB,precioB,subtotalB);
    }
    if (numC !=0)
    {
        printf("  Kit Embrague              %.0f                      %.2f                      %.2f",numC,precioC,subtotalC);
    }
    if (numD !=0)
    {
        printf("  Faros                     %.0f                      %.2f                      %.2f",numD,precioD,subtotalD);
    }
    if (numE !=0)
    {
        printf("  Radiador                  %.0f                      %.2f                      %.2f",numE,precioE,subtotalE);
    }

    printf("El subtotal es: %f\n",subtotal);
    printf("El total es: %f\n",total);

    return 0;
}