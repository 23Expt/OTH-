#include <stdio.h> 
#include <string.h>

int nilai_kartu(char kartu) {
    switch(kartu) {
        case 'J':
            return 11; 
        case 'Q':
            return 12; 
        case 'K':
            return 13; 
        case '1':
            return 10; 
        default:
            return kartu - '0';
    }
}

int main() {
    int n, i, j, min_swp = 0; 
    char card[100]; 
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %c", &card[i]);
    }
    
    for (i = 0; i < n; i++) {
        int min_idx = i;
        
        for (j = i + 1; j < n; j++) {
            if (nilai_kartu(card[j]) < nilai_kartu(card[min_idx])) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            char temp = card[i]; 
            card[i] = card[min_idx]; 
            card[min_idx] = temp; 

            
            min_swp++;
        } 
    }
    
    printf("%d\n", min_swp);
    return 0;
}