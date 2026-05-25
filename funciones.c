#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu(){
    int opc=0;
    printf("___Menu___\n");
    printf("1.Registrar producto\n");
    printf("2.Ver inventario\n");
    printf("3.Encontrar el producto mas caro y mas barato\n");
    printf("4.Buscar producto por nombre\n");
    printf(">> ");
    opc = validarEnteroConRango(1,4);
    return opc;
}

int registrarProducto(char nombres[10][20], float *precio, int *stock, int cont){
    printf("Ingrese el nombre del producto %d: ",cont);
    leerCadena(nombres[cont],20);
    printf("Ingrese el precio del producto %d: ",cont);
    *(precio + cont) = validarFloatConRango(0,10000);
    printf("Ingrese el stock del producto %d: ",cont);
    *(stock + cont) = validarEnteroConRango(0,1000);
    return cont + 1;
}

void verInventario(char nombres[10][20], float *precio, int *stock, int cont){
    float totalProducto = 0;
    float totalInventario = 0;
    float precioPromedio = 0;

    printf("#\t\tNombre\t\tStock\t\tPrecio\t\tTotal\n");

    for (int i = 0; i < cont; i++)
    {
        totalProducto = stock[i] * precio[i];
        totalInventario += totalProducto;
        precioPromedio+=precio[i];
        printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%.2f\n",i,nombres[i],stock[i],precio[i],totalProducto);
    }
    printf("Total inventario: %.2f\n",totalInventario);
    precioPromedio/=cont;
    printf("Precio promedio de los productos: %.2f\n",precioPromedio);
}

void encontrarMasCaro(char nombres[10][20], float *precio, int cont){
    float max = 0;
    int indice = 0;
    for (int i = 0; i < cont; i++)
    {
        if (precio[i] >= max)
        {
            max = precio[i];
            indice = i;
        }
    }
    printf("El producto mas caro es: %s con el precio: %.2f\n",nombres[indice],precio[indice]);
}

void buscarProducto(char nombres[10][20], float *precio, int cont){
    char nombreBuscar[20];
    int f=0;
    printf("Ingrese el nombre del producto que desea buscar: ");
    leerCadena(nombreBuscar,20);
    for (int i = 0; i < cont; i++)
    {
        if (strcmp(nombres[i],nombreBuscar)==0)
        {
            printf("Se encontro el producto\n");
            printf("Nombre: %s\n",nombres[i]);
            printf("Precio: %.2f\n",precio[i]);
            f=1;
            break;
        }
    }
    if (f==0)
    {
        printf("No se encontro el producto\n");
    }

}


void encontrarMasBarato(char nombres[10][20], float *precio, int cont){
    float min = 10000;
    int indice = 0;

    for (int i = 0; i < cont; i++)
    {
        if (precio[i] < min)
        {
            min = precio[i];
            indice = i;
        }
    }
    printf("El producto mas barato es: %s con un precio de: %.2f\n",nombres[indice],precio[indice]);
}

void leerCadena(char *cadena, int n){
    int len;
    fgets(cadena,n,stdin);
    len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

int validarEnteroConRango(int a, int b){
    int n;
    int aux;
    do
    {
        aux = scanf("%d",&n);
        while((getchar()) != '\n');
        if(aux != 1 || n < a || n > b){
            printf("El valor ingresado es incorrecto\n");
            printf(">> ");
        }
    } while (aux!=1 || n < a || n > b);
    return n;
}

float validarFloatConRango(int a, int b){
    float n;
    int aux;
    do
    {
        aux = scanf("%f",&n);
        while((getchar()) != '\n');
        if(aux != 1 || n < a || n > b){
            printf("El valor ingresado es incorrecto\n");
            printf(">> ");
        }
    } while (aux!=1 || n < a || n > b);
    return n;
}
