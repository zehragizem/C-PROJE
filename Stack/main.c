#include <stdlib.h>
#include <stdio.h>



// Yığının düğüm yapısı
struct node {
    int data; // Veri
    struct node* next; // Bir sonraki düğümün adresi
};

struct node* top = NULL;


// Yığının en üstüne eleman ekleyen fonksiyon
void push(int veri) {
    if(top==NULL){
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->data = veri; //aslında eleman en başa eklenir.
        new->next=NULL;
        top=new;
    }
    else{
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->data = veri; //aslında eleman en başa eklenir.
        new->next=top;
        top=new;
    }
  
}

int pop(void){ //kullanıcıdan veri alamayız çünkü en üstteki eleman silinir.
    if (top==NULL) {
        printf("Yigin bos!\n");
        return 1;
    }
    else{
        struct node *temp=top;
        top=top->next;
        return temp->data;
    }
}
void print(void){
    struct node *index =top; //stack'e top ile erişebiliriz.
    while(index!=NULL){
        printf("%d-",index->data);
        index=index->next;
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    print();
    pop();
    print();
    
    
    return 0;
}

