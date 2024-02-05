#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//girilen cümledeki birbirinden farklı tüm sesli harfleri bulur.
int sesli(char *dizi){
    int sayac=0;
    char sesli[15]={"aeıioöuü"};
    for(int i=0;i<strlen(dizi);i++){
        for(int j=0;j<15;j++){
            if(sesli[i]==dizi[j]){
                sayac++;
                break;
                
            }
        }
    }
    return sayac;
    
}
int main() {
    char dizi[70];
    printf("bir cümle girin:\n");
    gets(dizi);
    printf("%d\n",sesli(dizi));
    
    return 0;
}
