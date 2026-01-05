/*
 * Öðrenci Adý Soyadý: Ömer ERDOÐAN
 * Öðrenci Numarasý: 2010213005
 * Ödev Konusu: 1. Sparse Matrix Dönüþümü
 */
 
#include <stdio.h>

int main() {
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int size = 0;
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                size++;
            }
        }
    }

    int compactMatrix[20][3];
    int k = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[k][0] = i;
                compactMatrix[k][1] = j;
                compactMatrix[k][2] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    printf("Sparse Matrix Temsili (Row, Col, Value):\n");
    printf("---------------------------\n");
    for (i = 0; i < size; i++) {
        printf("%d \t %d \t %d\n", compactMatrix[i][0], compactMatrix[i][1], compactMatrix[i][2]);
    }

    return 0;
}
