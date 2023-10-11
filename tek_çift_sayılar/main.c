
#include <stdlib.h>
#include <stdio.h>

int main() {
    int sayi;
    printf("sayı girin:");
    scanf("%d",&sayi);
    
    if(sayi%2==0){
        printf("%d sayısı çifttir\n",sayi);
    }
    
    else{
        printf("%d sayısı tektir\n",sayi);
    }
    
    return 0;
}

