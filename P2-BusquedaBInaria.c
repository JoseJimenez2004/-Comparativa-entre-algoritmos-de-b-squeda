#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función de búsqueda binaria
int binary_search(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Si no se encuentra el elemento
}

int main() {
    int size;
    printf("Ingrese el tamaño de los datos de entrada: ");
    scanf("%d", &size);

    // Asignar memoria dinámica para el arreglo
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.");
        return 1;
    }

    // Inicializar el generador de números aleatorios con la hora actual
    srand(time(NULL));

    // Inicializar el arreglo con valores aleatorios entre -99 y 99
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 199 - 99; // Números entre -99 y 99
    }

    int key;
    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &key);

    // Calcular el tiempo de ejecución
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Realizar la búsqueda binaria
    int index = binary_search(arr, size, key);

    clock_gettime(CLOCK_MONOTONIC, &end);
    double execution_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    if (index != -1) {
        printf("El elemento %d se encuentra en el índice %d.\n", key, index);
    } else {
        printf("El elemento %d no se encuentra en el arreglo.\n", key);
    }

    printf("Tiempo de ejecución: %.10lf segundos.\n", execution_time); // Mostrar 10 dígitos después del punto decimal

    // Liberar la memoria asignada al arreglo
    free(arr);

    return 0;
}

