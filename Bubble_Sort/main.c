#include <stdlib.h>
#include <stdio.h>

void bubble_sort(int dizi[],int boyut){
    int temp;
    for(int i=1;i<boyut;i++){//işlemin kaç kez olacağı
        for(int j=0;j<boyut-1;j++){//hngi elemanların karşılaştırılıcağı
            if(dizi[j]>dizi[j+1]){
                temp=dizi[j];
                dizi[j]=dizi[j+1];
                dizi[j+1]=temp;
            }
        }
    }
    for(int i=0;i<boyut;i++){
        printf("%d-",dizi[i]);
    }
}




int main() {
    int dizi[]={1,7,2,5,8,3,4,9,12};
    int boyut=sizeof(dizi)/sizeof(dizi[0]);
    printf("boyut:%d\n",boyut);
    bubble_sort(dizi,boyut);
   
    return 0;
}
