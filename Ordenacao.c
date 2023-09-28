#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    int opcao;

    int Algoritmo_A[10];

    printf("\n---------------------------------------------\n");
    printf("\n--------- Algoritmos de Ordenação ----------\n");
    printf("\n");
    printf("[1] - QUICK SORT\n");
    printf("[2] - INSERTION SORT\n");
    printf("[3] - MERGE SORT\n");
    printf("\n");
    printf("\n----------------------------------------------\n");
    printf("Digite o índice do algoritmo desejado: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 1:
        printf("\nOpção escolhida foi: QUICK SORT\n\n");
        printf("Preenchendo o array com números aleatórios de 0 a 100:\n\n");
        srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

        for (int i = 0; i < 10; i++) {
            Algoritmo_A[i] = rand() % 101; // Gera números aleatórios de 0 a 100
        }

        printf("Array gerado:\n\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", Algoritmo_A[i]);
        }
        printf("\n\n");

        clock_t start_quick = clock();
        quicksort(Algoritmo_A, 0, 9);
        clock_t end_quick = clock();

        printf("Array ordenado com Quick Sort:\n\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", Algoritmo_A[i]);
        }
        printf("\n");
        double elapsed_quick = (double)(end_quick - start_quick) / CLOCKS_PER_SEC;
        printf("\nTempo de execução: %.6f segundos\n\n", elapsed_quick);
        break;

    case 2:
        printf("\nOpção escolhida foi: INSERTION SORT\n\n");
        printf("Preenchendo o array com números aleatórios de 0 a 100:\n\n");
        srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

        for (int i = 0; i < 10; i++) {
            Algoritmo_A[i] = rand() % 101; // Gera números aleatórios de 0 a 100
        }

        printf("Array gerado:\n\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", Algoritmo_A[i]);
        }
        printf("\n\n");

        clock_t start_insertion = clock();
        // Implementação do insertion sort
        for (int i = 1; i < 10; i++) {
            int key = Algoritmo_A[i];
            int j = i - 1;
            
            // Mova os elementos do arranjo que são maiores que key
            // para uma posição à frente de sua posição atual
            while (j >= 0 && Algoritmo_A[j] > key) {
                Algoritmo_A[j + 1] = Algoritmo_A[j];
                j = j - 1;
            }
            Algoritmo_A[j + 1] = key;
        }
        clock_t end_insertion = clock();

        printf("Array ordenado com Insertion Sort:\n\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", Algoritmo_A[i]);
        }
        printf("\n");
        double elapsed_insertion = (double)(end_insertion - start_insertion) / CLOCKS_PER_SEC;
        printf("\nTempo de execução: %.6f segundos\n\n", elapsed_insertion);
        break;
      
    case 3:
        printf("\nOpção escolhida foi: MERGE SORT\n\n");
        printf("Preenchendo o array com números aleatórios de 0 a 100:\n\n");
        srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

        for (int i = 0; i < 10; i++) {
            Algoritmo_A[i] = rand() % 101; // Gera números aleatórios de 0 a 100
        }

        printf("Array gerado:\n\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", Algoritmo_A[i]);
        }
        printf("\n\n");

        clock_t start_merge = clock();
        mergeSort(Algoritmo_A, 0, 9);
        clock_t end_merge = clock();

        printf("Array ordenado com Merge Sort:\n\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", Algoritmo_A[i]);
        }
        printf("\n");
        double elapsed_merge = (double)(end_merge - start_merge) / CLOCKS_PER_SEC;
        printf("\nTempo de execução: %.6f segundos\n\n", elapsed_merge);
        break;

    default:
        printf("\ec\e[3J");
        printf("\nOpção Inválida - Tente novamente!\n\n");
        break;
    }

    return 0;
}