#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//kuyruğa sadece  rastgele üretilen çift sayıları ekleyen kod

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rare=NULL;

int ekle(void){
    int veri=0;
    int sayac=0;
    srand(time(NULL));
    printf("üretilen sayılar:");
    while(sayac<=10){
        veri= rand() %100;
        printf("%d-",veri);
        if(front==NULL && veri%2==0){
            struct node *new=(struct node *)malloc(sizeof(struct node));
            new->data=veri;
            new->next=NULL;
            front=rare=new;
            sayac++;
        }
        else{
            struct node *new=(struct node *)malloc(sizeof(struct node));
            if(veri%2==0){
                new->data=veri;
                rare->next=new;
                rare=new;
                sayac++;
        }
            sayac++;
        }
      
 
    }
    printf("\n");
   
       
  
    return 1;
}

void print(void){
    if(front==NULL)
        printf("kuyruk boş\n");
    struct node *index=front;
    printf("listemiz:");
    while(index!=NULL){
        printf("%d-",index->data);
        index=index->next;
    }
    printf("\n");
}


int main() {
    ekle();
    print();
    return 0;
}

