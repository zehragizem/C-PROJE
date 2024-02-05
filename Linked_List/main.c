#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;

int addNodeEnd(void){
    int data=0;
    printf("eklemek istediğiniz veriyi girin:\n");
    scanf("%d",&data);
  
    if(head==NULL){  //yani ortada bir bağlı liste yoksa.
        struct node *new=(struct node*)malloc(sizeof(struct node)); //yeni bir düğüm yaratılır.
        new->data=data;
        new->next=NULL;
        head=tail=new; //head ve tail aynı düğümü gösterir çünkü 1 tane var.
    }
    else{
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;
        tail->next=new;  //sondan eklemede tail'i ayarlamak lazım.
        tail=new;
    }
    return 1;
}

int addNodeFirst(void){
    int data=0;
    printf("eklemek istediğiniz veriyi girin:\n");
    scanf("%d",&data);
    if(head==NULL){
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=NULL;
        head=tail=new;
        
    }
    else{
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=data;
        new->next=head;
        head=new;  //baştan eklemede head'i güncellemek lazım.
    }
    return 1;
}

int addNodeBetween(void){
    int data=0,data2=0;//data2 önüne eklenme yapılacak düğümün datasını gösteriyor.
    printf("hangi veriden önce eklemek istediğinizi ve eklenecek veriyi girin:\n");
    scanf("%d %d",&data2,&data);
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    struct node *index=head;
    while(index->next->data!=data2){ //önüne eklemek istediğimiz düğümden bir önceki düğümü bulur.
        index=index->next;
    }
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=index->next;//ekleme yapacağımız aralığın başı index sonu ise temp oldu.
    index->next=new;
    new->next=temp;//araya ekleme işlemi tamamlanmış oldu.
    return 1;
}

int delete(void){
    int veri=0;
    printf("silmek istediğiniz veriyi girin:\n");
    scanf("%d",&veri);
    struct node *prev=NULL;
    struct node *index=head;
    
    if(head==NULL){
        printf("linked list is empty\n");
        return 1;
    }
    // head siliceksen
    if(head->data==veri){
        head=head->next;
        free(index);
        return 1;
    }
    while(index!=NULL && index->data!=veri){  //bu sayede  listede geziyoruz eğer eleman bulunamazsa index null olarak çıkar
        prev=index;                         //eğer eleman bulunursa index aradığımız elemana eşittir
        index=index->next;                   //döngüye girmez bu sayede aradığımız elemandan bir öncekini(prev) tutmuş oluruz.
    }
    //aranan eleman yoksa
    if(index==NULL){
        printf("data is not found\n");
        return 1;
    }
    // silinmek istenen eleman tail ise
    if(tail->data==veri){
        tail=prev;
        tail->next=NULL;
        return 1;
    }
    prev->next=index->next;//elemanı silmek için bağları ayarladık.artık silinmek istenen elemana bağlı değiliz
    free(index);
    return 1;
    
}

void print(void){
    printf("listemiz:");
    struct node *index=head; //bağlı listeye head üstünden erişebiliriz.
    while(index!=NULL){  //index null olana kadar listede gezicek.
        printf("%d-",index->data);
        index=index->next; //yazdırdıktan sonra index'i bir sonrakine eşitliyoruz.
    }
    printf("\n");
}

int search(void){
    int veri=0;
    printf("aramak istediğiniz veriyi girin:\n");
    scanf("%d",&veri);
    int sayac=1,kontrol=0;
    struct node *index=head;
    if(head==NULL)
        printf("linked list is empty\n");
    while(index!=NULL){
        if(index->data==veri){
            printf("aranan eleman bulundu %d.dugum\n",sayac);
            kontrol=1;
            break;
        }
        sayac++;
        index=index->next;
    }
    if(kontrol==0){
        printf("aranan eleman bulunamadı\n");
    }
    
    return 1;
}

int uzunluk(void){
    int sayac=0;
    struct node *index=head; //bağlı listeye head üstünden erişebiliriz.
    while(index!=NULL){  //index null olana kadar listede gezicek.
        sayac++;
        index=index->next; //yazdırdıktan sonra index'i bir sonrakine eşitliyoruz.
    }
    printf("eleman sayısı:%d\n",sayac);
    
    return 1;
}

int sırala(void){
    int sayac=5,hold=0;
    if(head==NULL){
        printf("linked list is empty\n");
        return 1;
    }
    printf("sıralanmış hali:\n");
    for(int i=0;i<sayac+1;i++){
        struct node *gez=head;
        for(int j=0;j<sayac;j++){
            if(gez->next==NULL){
                break;
            }
            if((gez->data)>(gez->next->data)){
                hold=gez->data;
                gez->data=gez->next->data;
                gez->next->data=hold;
            }
            gez=gez->next;
        }
    }
    return 1;
}
int dosyaya_yaz(void){
    FILE *fp;
    struct node *index=head;
    fp=fopen("/Users/gizem/Desktop/linkedlist.txt","w");
    if(fp==NULL){
        puts("dosya açılamadı");
        return 1;
    }
    else{
        while(index!=NULL){
            fprintf(fp,"%d\n",index->data);
            index=index->next;
        }
        printf("dosyaya yazıldı.\n");
        fclose(fp);
        return 1;
        
}
}

int dosyadan_oku_listeyarat(void){
    FILE *fp;
    int adet=0;
    fp=fopen("/Users/gizem/Desktop/linkedlist.txt","r");
    while(!feof(fp)){
        struct node *okunan=(struct node*)malloc(sizeof(struct node));
        fscanf(fp,"%d",&okunan->data);
        printf("%d %d\n",adet,okunan->data);
        adet++;
        
        if(head==NULL){
            struct node *new=(struct node*)malloc(sizeof(struct node));
            new->data=okunan->data;
            new->next=NULL;
            head=tail=new;
        }
        else if(okunan->data!='\0'){
            struct node *new=(struct node*)malloc(sizeof(struct node));
            new->data=okunan->data;
            new->next=NULL;
            tail->next=new;
            tail=new;
            
        }
    }
    fclose(fp);
    return 1;
    
}

int guncelle(void){
    int guncel=0,veri=0;
    struct node *index=head;
    printf("güncellemek istediğiniz veriyi ve guncel veriyi girin:\n");
    scanf("%d %d",&veri,&guncel);
    while(index!=NULL){
        if(index->data==veri){
            index->data=guncel;
            printf("güncellendi.\n");
            break;
        }
        index=index->next;
    }
    return 1;
}


int main() {
    int secim=0,secim2=0;
    while(1){
        printf("Menü:\n1-ekle,2-sil,3-ara,4-sırala,5-uzunluk,6-print,7-dosyaya_yaz,8-guncelle,9-dosyadan oku,10-çıkış\n");
        scanf("%d",&secim);
        if(secim==1){
                printf("1-başa ekle,2-araya ekle,3-sona ekle\n");
                scanf("%d",&secim2);
                if(secim2==1){
                    addNodeFirst();
                    print();
                }
                else if(secim2==2){
                    print();
                    addNodeBetween();
                    print();
                }
                else if(secim2==3){
                    addNodeEnd();
                    print();
                }
        
    }
        else if(secim==2){
            delete();
            print();
        }
        else if(secim==3){
            search();
            print();
        }
        else if(secim==4){
            sırala();
            print();
        }
        else if(secim==5){
            uzunluk();
            print();
        }
        else if(secim==6){
            print();
        }
        else if(secim==7){
            dosyaya_yaz();
          
        }
        else if(secim==8){
            guncelle();
            print();
        }
        else if(secim==9){
            dosyadan_oku_listeyarat();
            print();
        }
        else if(secim==10){
            printf("çıkış yapıldı.\n");
            break;
        }
        else
            printf("yanlış karakter tekrar deneyin!\n");
        
        
    }

 
        
    }
