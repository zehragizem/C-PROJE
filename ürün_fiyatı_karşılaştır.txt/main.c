#include <stdlib.h>
#include <stdio.h>

//ürünler dosyasını okuyarak fiyatı 1000 tl den az olan ürünleri az.txt dosyasına ekler fiyatı 1000 tl den fazla olanları fazla.txt dosyasına ekler.
struct oku{
    char urunadı[20];
    int fiyat;
};
int main() {
    int sayac=0;
    FILE *p;
    FILE *dosya1;
    FILE *dosya2;
    dosya1=fopen("/Users/gizem/Desktop/az.txt","a");
    dosya2=fopen("/Users/gizem/Desktop/fazla.txt","a");
    p=fopen("/Users/gizem/Desktop/ürünler.txt","r");
    struct oku okunan[10];
    while(!feof(p)){
        fscanf(p,"%s %d",okunan[sayac].urunadı,&okunan[sayac].fiyat);
        if(okunan[sayac].fiyat<1000){
            fprintf(dosya1,"%s %d\n",okunan[sayac].urunadı,okunan[sayac].fiyat);
        }
        else{
            fprintf(dosya2,"%s %d\n",okunan[sayac].urunadı,okunan[sayac].fiyat);
        }
        sayac++;
    }
    fclose(p);
    fclose(dosya1);
    fclose(dosya2);
    printf("işlemler tamamlandı\n");
    
  
    return 0;
}
