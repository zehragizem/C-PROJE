#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 30
//agac1.txt dosyasındaki tekrarlı yazılan kelimleri okur ve birbirinden farklı olan kelimeleri bir diziye kaydeder daha sonra diziye kaydettiği kelimeleri sıralar ve ikili aramayı kullanarak kullanıcının aradığı kelimenin olup olmadığını söyler.


int elemanSayisi=0;
void ikiliArama(char dizi[][100],char* aranan,int sol,int sag){
    while(sol<=sag){
        int orta=(sol+sag)/2;
        if(strcmp(dizi[orta],aranan)==0){
            printf("\naranan kelime bulundu!\n");
            return;}
        else if(strcmp(dizi[orta],aranan)>0)//aranan daha küçükse sola gidilir.
            sag=orta-1;
        else//aranan daha büyükse sağa gidilir.
            sol=orta+1;
    }
    printf("\naranan kelime bulunamadı!\n");
}
 void sırala(char dizi[][100],int boyut){
    char temp[100];
    for(int i=1;i<boyut;i++){
        for(int j=0;j<boyut-1;j++){
            if(strcmp(dizi[j],dizi[j+1])>0){
                strcpy(temp,dizi[j]);
                strcpy(dizi[j],dizi[j+1]);
                strcpy(dizi[j+1],temp);
            }
        }
    }
    printf("\nsıralanmış dizi...\n");
    for (int i = 0; i <boyut; i++)
        printf("%s, ", dizi[i]);
    }
int dosyaOku_farkıBul(char dizi[][100]){
    FILE *dosya;
    char okunan[100];
    dosya = fopen("/Users/gizem/desktop/agac1.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açma hatası!");
        return 1;}
    while (!feof(dosya)) {
        int tekrar = 0;
        fscanf(dosya, "%s", okunan);
        for (int j = 0; j < elemanSayisi; j++) {
            if (strcmp(dizi[j], okunan) == 0) {
                tekrar = 1;
                break;}
          }
          // Aynı eleman daha önce eklenmediyse, diziye ekliyoruz
        if (!tekrar) {
            strcpy(dizi[elemanSayisi],okunan);
            elemanSayisi++;}
       }
    fclose(dosya);
    printf("\nyeni dizi oluşturuldu...\n");
    for (int i = 0; i <elemanSayisi; i++)
        printf("%s, ", dizi[i]);
    printf("\n");
    return 0;
    }


    
int main(){
    char dizi[100][100];
    char aranan[N];
    printf("aramak istediğiniz kelimeyi girin:\n");
    scanf("%s",aranan);
    dosyaOku_farkıBul(dizi);
    sırala(dizi,elemanSayisi);
    ikiliArama(dizi,aranan,0,elemanSayisi-1);


   
    
}
    

