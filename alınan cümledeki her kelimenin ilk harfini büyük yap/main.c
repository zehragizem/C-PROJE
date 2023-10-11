#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// kullanıcının girdiği cümlenin her kelimesinin ilk harfini büyük yapan kod.
char *baslik(char *dizi){
    int i=0;
    dizi[0]=toupper(dizi[0]);
    while(dizi[i]!='\0' && i<30){
        if(dizi[i]==' '){
            dizi[i+1]=toupper(dizi[i+1]);
        }
        i++;
    }
    return dizi;
}
int main() {
    char dizi[130];
    printf("bir cümle giriniz:\n");
    gets(dizi);
    printf("%s",baslik(dizi));
    
    return 0;
}
