#include <stdlib.h>
#include <stdio.h>
//mesaj1 adlı diziyi mesaj2 adlı diziye kopyalayan kod.
int main(){
    char mesaj1[100] = "C İle programlama Dersine Hoş geldiniz";
    char mesaj2[100];
    char* p1 = mesaj1;
    char* p2 = mesaj2;
    do {
    *p2 = *p1;
    p1++;
    p2++;
    } while (*(p1-1)!='\0');
    
    printf("%s",mesaj2);
}
