/*
 * Öðrenci Adý Soyadý: Ömer ERDOÐAM
 * Öðrenci Numarasý: 2010213005
 * Ödev Konusu: 1. Hanoi Ödevi
 */
#include <stdio.h>


void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    
    if (n == 1) {
        printf("\n Disk 1 þuradan: %c -> þuraya taþýndý: %c", from_rod, to_rod);
        return;
    }
    
   
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
    
    printf("\n Disk %d þuradan: %c -> þuraya taþýndý: %c", n, from_rod, to_rod);
    
    
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3;
    printf("%d Disk icin Hanoi Cozumu:\n", n);
    
  
    towerOfHanoi(n, 'A', 'C', 'B'); 
    
    printf("\n");
    return 0;
}
