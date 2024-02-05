#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 150

void harfsay(char *dizi) {
    int enbuyuk = 0;
    bool kontrol = false;
    char kr = '\0';
    int adet[35] = {0};  // Alfabe boyutunda olmalı
    char alfabe[35] = "abcdefghijklmnoprstuvyz";

    for (int i = 0; i < strlen(alfabe); i++) {
        for (int j = 0; j < strlen(dizi); j++) {
            if (alfabe[i] == dizi[j])
                adet[i] += 1;
        }
    }

    for (int i = 0; i < strlen(alfabe); i++) {
        if (adet[i] > enbuyuk) {
            enbuyuk = adet[i];
            kr = alfabe[i];
        }
    }

    for (int i = 0; i < strlen(alfabe); i++) {
        for (int j = i + 1; j < strlen(alfabe); j++) {
            if (adet[i] == adet[j] && adet[i] == enbuyuk) {
                kontrol = true;
            }
        }
    }

    if (kontrol) {
        printf("En çok tekrar eden harf yok aynı sayıda tekrar eden harfler var.");
    } else {
        printf("En çok tekrar eden harf:%c sayısı:%d\n", kr, enbuyuk);
    }
}

int main() {
    char dizi[N];
    printf("Bir cümle girin:");
    gets(dizi);
    harfsay(dizi);
    return 0;
}


