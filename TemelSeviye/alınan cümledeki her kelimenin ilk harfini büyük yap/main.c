#include <stdlib.h>
#include <stdio.h>
#define N 180
// kullanıcının girdiği cümlenin her kelimesinin ilk harfini büyük harf yapan kod.
char *baslik(char *dizi){
    int i=0;
    dizi[0]=toupper(dizi[0]);
    while(dizi[i]!='\0' && i<strlen(dizi)){
        if(dizi[i]==' '){
            dizi[i+1]=toupper(dizi[i+1]);
        }
        i++;
    }
    return dizi;
}
int main() {
    char dizi[N];
    printf("bir cümle giriniz:\n");
    gets(dizi);
    printf("%s",baslik(dizi));
    
    return 0;
}
