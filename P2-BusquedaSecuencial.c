#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busquedaSecuencial(int arreglo[], int n, int elemento) {
    int i = 0;
    
	for (i = 0; i < n; i++) {
        if (arreglo[i] == elemento) {
            return i;  
        }
    }
    return -1; 
}

int main() {
    int n, i, elementoBuscado, resultado = 0;
    double tiempoEjecucion;
    clock_t inicio, fin;

    printf("Ingrese el tamanio del arreglo: \n");
    scanf("%d", &n);

    //memoria para el arreglo utilizando malloc
    int *arreglo = (int *)malloc(n * sizeof(int));

    if (arreglo == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    //Generador de n�meros aleatorios con la hora actual
    srand(time(NULL));

    // Inicializar el arreglo con valores aleatorios entre -99 y 99
    for (i = 0; i < n; i++) {
        arreglo[i] = rand() % 199 - 99;
    }
    
    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &elementoBuscado);
	
	// Medir el tiempo de ejecuci�n
    inicio = clock();
	
    resultado = busquedaSecuencial(arreglo, n, elementoBuscado);

    fin = clock();
    
    tiempoEjecucion = ((double)(fin - inicio)) / CLOCKS_PER_SEC;

    if (resultado != -1) {
        printf("Elemento encontrado en el indice %d\n", resultado);
    } else {
        printf("Elemento no encontrado en el arreglo\n");
    }

    printf("Tiempo de ejecucion: %.10lf segundos\n", tiempoEjecucion);

    // Liberar la memoria asignada con malloc
    free(arreglo);

    return 0;
}

