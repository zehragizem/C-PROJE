#include <stdlib.h>
#include <stdio.h>

int main() {
    int i,j;
    for(i=2;i<=100;i++){
        int kontrol=0;
        for(j=2;j<i;j++){  //i=j olduğu için 2 döngüye girmiyor aşağıda direkt yazdırılıyor
            if(i%j==0)
                kontrol=1;
        }
        if(kontrol==0)
            printf("%d ",i);
    }
    printf("\n");
    return 0;
}
