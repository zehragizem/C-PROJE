#include <stdlib.h>
#include <stdio.h>

int ikiliArama(int dizi[],int aranan,int sol,int sag){
    while(sol<=sag){
        int orta=(sol+sag)/2;
        if(dizi[orta]==aranan)
            return orta;
        else if(dizi[orta]>aranan)//aranan daha küçükse sola gidilir.
            sag=orta-1;
        else//aranan daha büyükse sağa gidilir.
            sol=orta+1;
    }
    return -1;
}

int main() {
    int dizi[]={1,5,6,8,10,12,13,15,22,25,27,30};
    int boyut=sizeof(dizi)/sizeof(dizi[0]);
    int sayi;
    printf("aranacak sayıyı girin:\n");
    scanf("%d",&sayi);
    int sonuc=ikiliArama(dizi,sayi,0,boyut-1);
    if(sonuc==-1)
        printf("aranan bulunamadı!\n");
    else
        printf("aranan bulundu!\n");
    return 0;
}
