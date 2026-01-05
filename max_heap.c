/*
 * Öðrenci Adý Soyadý: Ömer ERDOÐAN
 * Öðrenci Numarasý: 2010213005
 * Ödev Konusu: Max ve Min Heap Uygulamasý
 */

#include <stdio.h>

int sizeMax = 0;
int sizeMin = 0;

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapifyMax(int array[], int size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] > array[largest])
        largest = l;
    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapifyMax(array, size, largest);
    }
}

void heapifyMin(int array[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && array[l] < array[smallest])
        smallest = l;
    if (r < size && array[r] < array[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&array[i], &array[smallest]);
        heapifyMin(array, size, smallest);
    }
}

void insertMax(int array[], int newNum) {
    int i;
    if (sizeMax == 0) {
        array[0] = newNum;
        sizeMax += 1;
    } else {
        array[sizeMax] = newNum;
        sizeMax += 1;
        for (i = sizeMax / 2 - 1; i >= 0; i--) {
            heapifyMax(array, sizeMax, i);
        }
    }
}

void insertMin(int array[], int newNum) {
    int i;
    if (sizeMin == 0) {
        array[0] = newNum;
        sizeMin += 1;
    } else {
        array[sizeMin] = newNum;
        sizeMin += 1;
        for (i = sizeMin / 2 - 1; i >= 0; i--) {
            heapifyMin(array, sizeMin, i);
        }
    }
}

void deleteRootMax(int array[], int num) {
    int i;
    for (i = 0; i < sizeMax; i++) {
        if (num == array[i])
            break;
    }

    swap(&array[i], &array[sizeMax - 1]);
    sizeMax -= 1;
    for (i = sizeMax / 2 - 1; i >= 0; i--) {
        heapifyMax(array, sizeMax, i);
    }
}

void deleteRootMin(int array[], int num) {
    int i;
    for (i = 0; i < sizeMin; i++) {
        if (num == array[i])
            break;
    }

    swap(&array[i], &array[sizeMin - 1]);
    sizeMin -= 1;
    for (i = sizeMin / 2 - 1; i >= 0; i--) {
        heapifyMin(array, sizeMin, i);
    }
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int arrayMax[10];
    int arrayMin[10];

    printf("--- MAX HEAP ISLEMLERI ---\n");
    insertMax(arrayMax, 3);
    insertMax(arrayMax, 4);
    insertMax(arrayMax, 9);
    insertMax(arrayMax, 5);
    insertMax(arrayMax, 2);

    printf("Max Heap: ");
    printArray(arrayMax, sizeMax);

    deleteRootMax(arrayMax, 9);
    printf("Max Heap (Root Silindi): ");
    printArray(arrayMax, sizeMax);

    printf("\n--- MIN HEAP ISLEMLERI ---\n");
    insertMin(arrayMin, 3);
    insertMin(arrayMin, 4);
    insertMin(arrayMin, 9);
    insertMin(arrayMin, 5);
    insertMin(arrayMin, 2);

    printf("Min Heap: ");
    printArray(arrayMin, sizeMin);

    deleteRootMin(arrayMin, 2); 
    printf("Min Heap (Root Silindi): ");
    printArray(arrayMin, sizeMin);

    return 0;
}
