/*
 * Öðrenci Adý Soyadý: Ömer ERDOÐAN
 * Öðrenci Numarasý: 2010213005
 * Ödev Konusu: Array de ekleme silme iþlemleri
 */

#include <stdio.h>

void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertElement(int arr[], int n, int capacity, int x, int pos) {
    int i;
    if (n >= capacity) {
        return n; 
    }
    
    for (i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = x;
    return n + 1;
}

int deleteElement(int arr[], int n, int pos) {
    int i;
    if (pos >= n || pos < 0) {
        return n;
    }
    
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5; 
    int capacity = 100;

    printf("Orijinal Dizi: ");
    display(arr, n);

    n = insertElement(arr, n, capacity, 25, 2);
    printf("2. Indekse 25 Eklendi: ");
    display(arr, n);

    n = deleteElement(arr, n, 3); 
    printf("3. Indeksteki Silindi: ");
    display(arr, n);

    return 0;
}
