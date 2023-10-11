#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//girilen cümlede en çok tekrar eden harfi ve tekrarlama sayısını bulan kod.
void harfsay(char *dizi){
    int sayac=0;
    int enbuyuk=0;
    char kr='\0';
    char alfabe[35]={"abcdefghijklmnoprstuvyz"};
    for(int i=0;i<strlen(alfabe);i++){
        for(int j=0;j<strlen(dizi);j++){
            if(alfabe[i]==dizi[j]){
                sayac++;
            }
        }
        if(i==0){
            enbuyuk=sayac;
            kr=dizi[i];
            
        }
        else{
            if(sayac>enbuyuk){
                enbuyuk=sayac;
                kr=dizi[i];
            }
                
        }
        
    }
    printf("en çok tekrar eden harf:%c ve sayısı:%d\n",kr,enbuyuk);
    
    
    
}
int main() {
    char dizi[100];
    printf("bir cümle girin:\n");
    gets(dizi);
    harfsay(dizi);
    
    return 0;
}
