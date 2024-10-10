#include <stdio.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Función para obtener el valor máximo en arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Función para realizar el conteo (counting sort) de arr[] 
// según el dígito representado por exp.
void countSort(int arr[], int n, int exp) {
    int output[n];  // Array de salida
    int count[10] = { 0 };  // Inicialización del array de conteo

    print(arr, n);
    // Almacenar el conteo de ocurrencias en count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    print(count, 10);
    // Cambiar count[i] para que ahora contenga la posición actual 
    // de este dígito en el array de salida
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    print(count, 10);
    // Construir el array de salida
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copiar el array de salida a arr[], de modo que arr[] ahora 
    // contenga los números ordenados según el dígito actual
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    print(arr, n);
}

// Función principal que ordena arr[] de tamaño n usando Radix Sort
void radixsort(int arr[], int n) {
    // Obtener el número máximo para conocer el número de dígitos
    int m = getMax(arr, n);

    // Hacer counting sort para cada dígito
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Función principal para ejecutar el código
int main() {
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Llamada a la función Radix Sort
    radixsort(arr, n);

    // Imprimir el array ordenado
    print(arr, n);
    return 0;
}
 