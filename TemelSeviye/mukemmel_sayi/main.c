#include <stdlib.h>
#include <stdio.h>
//mukemmel sayı kendisi dışındaki bölenlerinin toplamı kendisine eşit olan sayıdır.
int main() {
    int sayi,i,toplam=0;
    printf("bir sayı giriniz:");
    scanf("%d",&sayi);
    
    
    for(i=1;i<=sayi;i++){
        if(sayi%i==0){
            printf("%d ",i);
            toplam+=i;
        }
        
    }
    if(toplam==2*sayi){
        printf("%d sayısı mükemmel sayıdır\n",sayi);
        
    }
    else{
        printf("%d sayısı mükemmel sayı değildir\n",sayi);
    }
    
    return 0;
}
