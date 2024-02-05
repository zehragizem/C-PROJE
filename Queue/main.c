#include <stdlib.h>
#include <stdio.h>


//kuyruğa ilk giren ilk çıkar.Yani silme işlemi front'ı düzenleyerek olur.
//ekleme işlemi sondan olur.Yani ekleme işlemi rear'ı düzenleyerek olur.

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rare=NULL;

int ekle(int veri){
        if(front==NULL){
            struct node *new=(struct node *)malloc(sizeof(struct node));
            new->data=veri;
            new->next=NULL;
            front=rare=new;

        }
        else{
            struct node *new=(struct node *)malloc(sizeof(struct node));
            new->data=veri;
            rare->next=new;
            rare=new;
         
        }
    return 1;
}

void print(void){
    if(front==NULL)
        printf("kuyruk boş\n");
    struct node *index=front;
    printf("listemiz:");
    while(index!=NULL){
        printf("%c-",index->data);
        index=index->next;
    }
    printf("\n");
}

int sil(void){
    if(front==NULL){
        printf("kuyruk boş\n");
        return 1;
    }
    struct node *temp=front;
    front=front->next;
    free(temp);
       
    return 1;
}


int main() {
    ekle('E');
    ekle('A');
    ekle('C');
    print();
    sil();
    print();
    
 
   
    return 0;
}


