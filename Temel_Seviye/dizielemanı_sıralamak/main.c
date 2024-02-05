#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//bir karakter dizisindeki elemanları strcmp ve bubble sorttan yararlanarak sıralar.
int main() {
    char dizi[7][30]={"bug","bugunlerde","buglar","bugunlere","ozel","oldu"};
    char hold[20];
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(strcmp(dizi[j],dizi[i])>0){
                strcpy(hold,dizi[j]);
                strcpy(dizi[j],dizi[i]);
                strcpy(dizi[i],hold);
            }
        }
    }
    for(int i=0;i<7;i++){
        printf("%s\n",dizi[i]);
    }
    

}

