#include <stdlib.h>
#include <stdio.h>

int main(){
    int sayi,i,kontrol=0;
    printf("bir sayı gir:");
    scanf("%d",&sayi);
    printf("sayının bölenleri:");
    for(i=1;i<=sayi;i++){
        if(sayi%i==0)
            printf("%d ",i);
    }
    printf("\n");
    
    for(i=2;i<sayi;i++){
        if(sayi%i==0)
            kontrol=1;
    }
    
    if(sayi==1)
        printf("%d sayısı asal değil",sayi);
    else{
        if(kontrol==0)
            printf("sayı asal:%d\n",sayi);
        else
            printf("%d sayısı asal değil\n",sayi);
        }
    
    return 0;
}
