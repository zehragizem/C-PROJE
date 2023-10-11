#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Palindrom(char* dizi){
    int kontrol=0;
    unsigned long uzunluk=strlen(dizi);
    for(int i=0;i<uzunluk;i++){
        if(dizi[i]!=dizi[uzunluk-i-1]){
            printf("palindrom kelime değil\n");
            kontrol=1;
            break;}
    }
    if(kontrol==0)
        printf("palindrom kelimedir\n");
    
    
}

int main(){
    char dizi[30];
    printf("bir kelime girin:\n");
    scanf("%s",dizi);
    Palindrom(dizi);
   

    return 0;
}



